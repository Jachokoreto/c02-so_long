#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*relative_path = "./sprite/character/AnyConv.com__tile013.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600,400, "bloop");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 100, 0);
	mlx_put_image_to_window(mlx, mlx_win, img, 100, 20);
	mlx_put_image_to_window(mlx, mlx_win, img, 100, 40);
	mlx_loop(mlx);

}
