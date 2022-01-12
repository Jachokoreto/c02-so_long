#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line.h"
# include "libft.h"
# include <mlx.h>

# include <stdio.h>

typedef struct s_root
{
	void	*mlx;
	void	*mlx_win;	
	void	*grass[3];
	void	*player[4];
	void	*wall[5];
	void	*collectible;

	char	**map;
	void	****map_data;
	int		map_height;
	int		map_width;

	int		offset_x;
	int		offset_y;

}				t_root;


void	load_images(t_root *root);
void	load_map(t_root *root);
void	draw_map(t_root *root);
int		key_hook(int keycode, t_root *root);

#endif