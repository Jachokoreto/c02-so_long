#include "so_long.h"

int    key_hook(int keycode, t_root *root)
{
	void	*blank;

	if (keycode == 126)
		root->offset_y -= 32;
	if (keycode == 125)
		root->offset_y += 32;
	if (keycode == 124)
		root->offset_x += 32;
	if (keycode == 123)
		root->offset_x -= 32;

	blank = mlx_new_image(root->mlx, 1024, 768);
	mlx_put_image_to_window(root->mlx, root->mlx_win, blank, 0 , 0);
	draw_map(root);
	return (0);
}