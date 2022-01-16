/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:11:03 by jatan             #+#    #+#             */
/*   Updated: 2022/01/16 12:37:11 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

void	check_map(t_root *root);
void	find_cep(char **str, int len, t_root *root);
void	init_map(t_root *root);
void	set_map_data(int i, int j, t_root *root);

// get all the line in the .ber file and store in
// temporary string
void	load_map(t_root *root, char *arg)
{
	int		fd;
	char	*tmp;
	char	*line;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		exit_error("Error\nCan't open file", root, 0);
	line = ft_strdup("");
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		line = ft_strjoin(line, tmp);
	}
	root->map = ft_split(line, '\n');
	if (root->map)
		check_map(root);
	init_map(root);
}

void	check_map(t_root *root)
{
	int		i;

	root->map_width = ft_strlen(root->map[0]);
	i = -1;
	while (root->map[++i])
	{
		if ((int)ft_strlen(root->map[i]) != root->map_width)
			exit_error("Map is not rectangular", root, 0);
	}
	root->map_height = i;
	i = -1;
	while (++i < root->map_width)
	{
		if (root->map[0][i] != '1' || root->map[root->map_height - 1][i] != '1')
			exit_error("Top or bottom edge is not wall", root, 0);
	}
	i = 0;
	while (++i < root->map_height - 2)
	{
		find_cep(root->map, root->map_height, root);
		if (root->map[i][0] != '1' || root->map[i][root->map_width - 1] != '1')
			exit_error("Left or right edge is not wall", root, 0);
	}
}

void	find_cep(char **str, int len, t_root *root)
{
	int		i;
	char	*to_find;
	int		found;

	to_find = ft_strdup("CEP");
	while (*to_find)
	{
		i = -1;
		found = 0;
		while (++i < len)
		{
			if (ft_strchr(str[i], *to_find))
			{
				found = 1;
				break ;
			}
		}
		if (found != 1)
			exit_error("Missing C/E/P in map", root, 0);
		to_find++;
	}
}

void	init_map(t_root *root)
{
	int	i;
	int	j;

	root->collectible_count = 0;
	root->map_data = malloc(sizeof(void ***) * root->map_height);
	i = -1;
	while (++i < root->map_height)
	{
		root->map_data[i] = malloc(sizeof(void **) * root->map_width);
		j = -1;
		while (root->map[i][++j])
		{
			root->map_data[i][j] = malloc(sizeof(void *) * 2);
			root->map_data[i][j][0] = root->grass[i * j % 3];
			set_map_data(i, j, root);
		}
	}
}

void	set_map_data(int i, int j, t_root *root)
{
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
