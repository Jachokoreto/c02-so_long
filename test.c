#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!, %d\n", keycode);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*relative_path = "./src/0.xpm";
	int		img_width;
	int		img_height;

	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 600, 300, "bloop");
	// img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	// mlx_put_image_to_window(mlx, mlx_win, img, 100, 0);
	// mlx_put_image_to_window(mlx, mlx_win, img, 100, 64);
	// mlx_put_image_to_window(mlx, mlx_win, img, 100, 64 * 2);

	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_loop(vars.mlx);

}
