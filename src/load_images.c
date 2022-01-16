/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 10:58:40 by jatan             #+#    #+#             */
/*   Updated: 2022/01/16 11:02:16 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	load_images(t_root *root)
{
	int		w;
	int		h;
	void	*mlx;

	mlx = root->mlx;
	root->grass[0] = mlx_xpm_file_to_image(mlx, "xpm/grass/0.xpm", &w, &h);
	root->grass[1] = mlx_xpm_file_to_image(mlx, "xpm/grass/1.xpm", &w, &h);
	root->grass[2] = mlx_xpm_file_to_image(mlx, "xpm/grass/2.xpm", &w, &h);
	root->collectible = mlx_xpm_file_to_image(mlx, "xpm/collect/0.xpm", &w, &h);
	root->player[0] = mlx_xpm_file_to_image(mlx, "xpm/player/0.xpm", &w, &h);
	root->player[1] = mlx_xpm_file_to_image(mlx, "xpm/player/1.xpm", &w, &h);
	root->player[2] = mlx_xpm_file_to_image(mlx, "xpm/player/2.xpm", &w, &h);
	root->player[3] = mlx_xpm_file_to_image(mlx, "xpm/player/3.xpm", &w, &h);
	root->wall[0] = mlx_xpm_file_to_image(mlx, "xpm/wall/0.xpm", &w, &h);
	root->wall[1] = mlx_xpm_file_to_image(mlx, "xpm/wall/1.xpm", &w, &h);
	root->wall[2] = mlx_xpm_file_to_image(mlx, "xpm/wall/2.xpm", &w, &h);
	root->wall[3] = mlx_xpm_file_to_image(mlx, "xpm/wall/3.xpm", &w, &h);
	root->wall[4] = mlx_xpm_file_to_image(mlx, "xpm/wall/4.xpm", &w, &h);
	root->exit = mlx_xpm_file_to_image(mlx, "xpm/exit/0.xpm", &w, &h);
}
