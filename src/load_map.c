/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:11:03 by jatan             #+#    #+#             */
/*   Updated: 2022/01/15 12:13:30 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

int		check_map(t_root *root);
void	init_map(t_root *root);

// get all the line in the .ber file and store in
// temporary string
void	load_map(t_root *root)
{
	int		fd;
	char	*tmp;
	char	*line;

	fd = open("map/simple.ber", O_RDONLY);
	if (fd == -1)
		exit_error("Error\nCan't open file", root, 1);
	line = ft_strdup("");
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		line = ft_strjoin(line, tmp);
	}
	root->map = ft_split(line, '\n');
	if (root->map && check_map(root) == 1)
		init_map(root);
}

void	check_map(t_root *root)
{
	char*   row_to_check;
	int     i;
	int     j;
	int     have_start;
	int     have_exit;
	int     have_collectible;

	i = 0;
	row_to_check = root->map[0];
	root->map_width = ft_strlen(row_to_check);
	while (row_to_check[i])
	{
		if (row_to_check[i++] != '1')
		{
			return (0);
		}
	}
	i = 1;
	while(root->map[i])
	{
		row_to_check = root->map[i++];
		if ((int)ft_strlen(row_to_check) != root->map_width)
		{
			printf("Not rectangular\n");
			return (0);
		}
		j = 0;
		while (row_to_check[j])
		{
			if (have_collectible != 1 && row_to_check[j] == 'C')
				have_collectible = 1;
			if (have_exit != 1 && row_to_check[j] == 'E')
				have_exit = 1;
			if (have_start != 1 && row_to_check[j] == 'P')
				have_start = 1;
			j++;
		}
		if (row_to_check[0] != '1' || row_to_check[j - 1] != '1')
		{
			printf("left or right edge is not 1: %c, %c\n", row_to_check[0], row_to_check[j - 1]);
			return (0);
		}
	}
	row_to_check = root->map[i - 1];
	j = 0;
	while (row_to_check[j])
	{
		if ((int)ft_strlen(row_to_check) != root->map_width)
		{
			printf("Not rectangular\n");
			return (0);
		}
		if (row_to_check[j++] != '1')
		{
			printf("bottom row is not 1\n");
			return (0);
		}
	}
	root->map_height = i;
	return (1);
}

void    init_map(t_root *root)
{
	int i;
	int j;

	root->collectible_count = 0;
	root->map_data = malloc(sizeof(void***) * root->map_height);
	i = -1;
	while (++i < root->map_height)
	{
		root->map_data[i] = malloc(sizeof(void**) * root->map_width);
		j = -1;
		while (root->map[i][++j])
		{
			root->map_data[i][j] = malloc(sizeof(void*) * 2);
			root->map_data[i][j][0] = root->grass[i * j % 3];

			if (root->map[i][j] == '1')
				root->map_data[i][j][1] = root->wall[i * j % 5];
			else if (root->map[i][j] == 'C')
			{
				root->map_data[i][j][1] = root->collectible;
				root->collectible_count++;
			}
			else if (root->map[i][j] == 'E')
				root->map_data[i][j][1] = root->exit;
			else if (root->map[i][j] == 'P')
			{
				root->map_data[i][j][1] = NULL;
				root->offset_x = j * 64;
				root->offset_y = i * 64;
			}
			else
				root->map_data[i][j][1] = NULL;
		}
	}
}

