/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 10:54:59 by jatan             #+#    #+#             */
/*   Updated: 2022/01/17 16:36:34 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_root *root, void **array, int size);
void	credits(void);

int	exit_game(t_root *root)
{
	int	i;
	int	j;

	destroy_images(root, root->grass, 3);
	destroy_images(root, &root->collectible, 1);
	destroy_images(root, root->player, 4);
	destroy_images(root, root->wall, 5);
	destroy_images(root, &root->exit, 1);
	i = -1;
	while (root->map[++i])
		free(root->map[i]);
	i = -1;
	while (++i < root->map_height)
	{
		j = -1;
		while (++j < root->map_width)
			free(root->map_data[i][j]);
		free(root->map_data[i]);
	}
	mlx_destroy_window(root->mlx, root->mlx_win);
	ft_putendl_fd("\033[0;32mEXIT GAME\033[0m", 1);
	credits();
	exit(0);
}

void	exit_error(char *msg, t_root *root, int state)
{
	int	i;

	if (state >= 0)
	{
		perror(ft_strjoin("\033[0;31mError\033[0m\n", msg));
	}
	if (state >= 1)
	{
		destroy_images(root, root->grass, 3);
		destroy_images(root, &root->collectible, 1);
		destroy_images(root, root->player, 4);
		destroy_images(root, root->wall, 5);
		destroy_images(root, &root->exit, 1);
		i = -1;
		while (root->map[++i])
			free(root->map[i]);
	}
	exit(0);
}

void	destroy_images(t_root *root, void **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		mlx_destroy_image(root->mlx, array[i]);
		i++;
	}
}

void	credits(void)
{
	ft_putendl_fd(	
		"====CREDITS====", 1);
	ft_putendl_fd(	
		"Sprout Lands Asset Pack by Cup Nooble on itch.io", 1);
	ft_putendl_fd(	
		"Isaac and Jun Han for the help and inspirations", 1);
}