/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:27:08 by jatan             #+#    #+#             */
/*   Updated: 2022/01/18 10:14:00 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_root	root;

	if (argc != 2)
		exit_error("Run with ./so_long map.ber", &root, 0);
	if (ft_strncmp(ft_strchr(argv[1], '.'), ".ber", ft_strlen(argv[1])) != 0)
		exit_error("Map file should be .ber", &root, 0);
	root.mlx = mlx_init();
	root.mlx_win = mlx_new_window(
			root.mlx, WIN_SIZE, WIN_SIZE, "so_long");
	root.player_steps = 0;
	root.exit_found = 0;
	root.player_found = 0;
	load_images(&root);
	load_map(&root, argv[1]);
	draw_map(&root);
	mlx_key_hook(root.mlx_win, key_hook, &root);
	mlx_hook(root.mlx_win, 17, 0, exit_game, &root);
	mlx_loop(root.mlx);
	return (0);
}
