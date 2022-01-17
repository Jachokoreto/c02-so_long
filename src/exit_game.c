/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 10:54:59 by jatan             #+#    #+#             */
/*   Updated: 2022/01/17 13:24:05 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_root *root, void **array, int size);

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
	ft_putendl_fd("\033[0;32mEXIT GAME", 1);
	ft_putendl_fd(	
		"Credit Sprout Lands Asset Pack by Cup Nooble on itch.io", 1);
	exit(0);
}

void	exit_error(char *msg, t_root *root, int state)
{
	int	i;

	if (state >= 0)
	{
		perror(ft_strjoin("Error\n", msg));
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
