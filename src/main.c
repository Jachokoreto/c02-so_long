#include "so_long.h"
# include <mlx.h>
// # include <stdlib.h>

int main(void)
{
    t_root  root;

    root.mlx = mlx_init();
    root.mlx_win = mlx_new_window(root.mlx, WIN_SIZE, WIN_SIZE, "jaja");

    // int w;
    // int h;
    // void *img;
    // char    *path = "./src/0.xpm";
    // img = mlx_xpm_file_to_image(mlx, path, &w, &h);

    // mlx_put_image_to_window(mlx, mlx_win, img, 100, 100);


    load_images(&root);
    load_map(&root);
    draw_map(&root);
    mlx_key_hook(root.mlx_win, key_hook, &root);
    mlx_hook(root.mlx_win, 17, 0, exit_game, &root);
    mlx_loop(root.mlx);

    // system("leaks so_long");
    return (0);
}

// print errors
// animation...?