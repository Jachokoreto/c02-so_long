/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 07:30:30 by jatan             #+#    #+#             */
/*   Updated: 2022/01/16 12:40:54 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wasd_keys(int key, t_root *root);

int	key_hook(int key, t_root *root)
{
	void	*blank;

	if (key == 126 || key == 125 || key == 124 || key == 123)
		wasd_keys(key, root);
	if (key == 53)
		exit_game(root);
	if (root->map[root->offset_y / 64][root->offset_x / 64] == 'C')
	{
		root->map[root->offset_y / 64][root->offset_x / 64] = '0';
		root->map_data[root->offset_y / 64][root->offset_x / 64][1] = NULL;
		root->collectible_count--;
	}
	if (root->collectible_count == 0
		&& root->map[root->offset_y / 64][root->offset_x / 64] == 'E')
		exit_game(root);
	blank = mlx_new_image(root->mlx, WIN_SIZE, WIN_SIZE);
	mlx_put_image_to_window(root->mlx, root->mlx_win, blank, 0, 0);
	draw_map(root);
	return (0);
}

void	wasd_keys(int key, t_root *root)
{
	if (key == 126)
	{
		if (root->map[(root->offset_y + 32) / 64 - 1]
			[root->offset_x / 64] != '1')
			root->offset_y -= 64;
	}
	else if (key == 125)
	{
		if (root->map[root->offset_y / 64 + 1]
			[root->offset_x / 64] != '1')
			root->offset_y += 64;
	}
	else if (key == 124)
	{
		if (root->map[root->offset_y / 64]
			[root->offset_x / 64 + 1] != '1')
			root->offset_x += 64;
	}
	else if (key == 123)
	{
		if (root->map[root->offset_y / 64]
			[(root->offset_x + 32) / 64 - 1] != '1')
			root->offset_x -= 64;
	}
	ft_putendl_fd(ft_strjoin("Steps: ",ft_itoa(++root->player_steps)), 1);
}
