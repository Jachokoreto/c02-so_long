/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 10:45:16 by jatan             #+#    #+#             */
/*   Updated: 2022/01/16 10:58:00 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(int x, int y, t_root *root);

void	draw_map(t_root *root)
{
	int	corner_x;
	int	corner_y;

	corner_x = WIN_SIZE / 2 - root->offset_x;
	corner_y = WIN_SIZE / 2 - root->offset_y;
	render_map(corner_x, corner_y, root);
	mlx_put_image_to_window(
		root->mlx, root->mlx_win, root->player[0],
		WIN_SIZE / 2 - 32, WIN_SIZE / 2 - 32);
}

void	render_map(int corner_x, int corner_y, t_root *root)
{
	int	i;
	int	j;

	i = -1;
	while (++i < root->map_height)
	{
		j = -1;
		while (++j < root->map_width)
		{
			mlx_put_image_to_window(
				root->mlx, root->mlx_win, root->map_data[i][j][0],
				corner_x + (j * 63) - 32, corner_y + (i * 63) - 32);
			if (root->map_data[i][j][1] != NULL)
			{
				mlx_put_image_to_window(
					root->mlx, root->mlx_win, root->map_data[i][j][1],
					corner_x + (j * 63) - 32, corner_y + (i * 63) - 32);
			}
		}
	}
}
