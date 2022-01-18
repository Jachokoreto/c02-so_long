/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:01:50 by jatan             #+#    #+#             */
/*   Updated: 2022/01/18 10:13:30 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line.h"
# include "libft.h"
# include <mlx.h>
# include <stdio.h>

# define WIN_SIZE 300

typedef struct s_root
{
	void	*mlx;
	void	*mlx_win;
	void	*grass[3];
	void	*player[4];
	void	*wall[5];
	void	*collectible;
	void	*exit;

	char	**map;
	void	****map_data;
	int		map_height;
	int		map_width;

	int		offset_x;
	int		offset_y;
	int		collectible_count;
	int		exit_found;
	int		player_found;

	int		player_x;
	int		player_y;
	int		player_steps;

}				t_root;

void	load_images(t_root *root);
void	load_map(t_root *root, char *arg);
void	draw_map(t_root *root);
int		key_hook(int keycode, t_root *root);
int		exit_game(t_root *root);
void	exit_error(char *msg, t_root *root, int state);
#endif
