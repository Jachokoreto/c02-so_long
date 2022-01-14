/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 07:30:30 by jatan             #+#    #+#             */
/*   Updated: 2022/01/15 07:30:55 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    key_hook(int keycode, t_root *root)
{
	void	*blank;
	int		x;
	int		y;

	if (keycode == 126 || keycode == 13)
	{
		if (root->map[(root->offset_y + 32) / 64 - 1][root->offset_x / 64] != '1')
			root->offset_y -= 64;
	}
	if (keycode == 125 || keycode == 1)
	{
		if (root->map[root->offset_y / 64 + 1][root->offset_x / 64] != '1') //root->offset_y / 64 < root->map_height - 2
			root->offset_y += 64;
	}
	if (keycode == 124 || keycode == 2)
	{
		if (root->map[root->offset_y / 64][root->offset_x / 64 + 1] != '1') //root->offset_y / 64 < root->map_height - 2
			root->offset_x += 64;
	}
	if (keycode == 123 || keycode == 0)
	{
		if (root->map[root->offset_y / 64][(root->offset_x + 32) / 64 - 1] != '1')
			root->offset_x -= 64;
	}
	if (keycode == 53)
		exit_game(root);
	if (root->map[root->offset_y / 64][root->offset_x / 64] == 'C')
	{
		root->map[root->offset_y / 64][root->offset_x / 64] = '0';
		root->map_data[root->offset_y / 64][root->offset_x / 64][1] = NULL;
		root->collectible_count--;
	}
	if (root->collectible_count == 0
		&& root->map[root->offset_y / 64][root->offset_x / 64] == 'E')
	{
		printf("Exiting;");
		exit_game(root);
	}
	blank = mlx_new_image(root->mlx, WIN_SIZE, WIN_SIZE);
	mlx_put_image_to_window(root->mlx, root->mlx_win, blank, 0 , 0);
	draw_map(root);
	return (0);
}
