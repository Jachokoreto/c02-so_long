#include "so_long.h"
#include <mlx.h>


void    load_images(t_root *root)
{
    int w;
    int h;

    root->grass[0] = mlx_xpm_file_to_image(root->mlx, "sprite/grass/0.xpm", &w, &h);
    root->grass[1] = mlx_xpm_file_to_image(root->mlx, "sprite/grass/1.xpm", &w, &h);
    root->grass[2] = mlx_xpm_file_to_image(root->mlx, "sprite/grass/2.xpm", &w, &h);

    root->collectible = mlx_xpm_file_to_image(root->mlx, "sprite/collectible/0.xpm", &w, &h);
    
    root->player[0] = mlx_xpm_file_to_image(root->mlx, "sprite/player/0.xpm", &w, &h);
    root->player[1] = mlx_xpm_file_to_image(root->mlx, "sprite/player/1.xpm", &w, &h);
    root->player[2] = mlx_xpm_file_to_image(root->mlx, "sprite/player/2.xpm", &w, &h);
    root->player[3] = mlx_xpm_file_to_image(root->mlx, "sprite/player/3.xpm", &w, &h);

    root->wall[0] = mlx_xpm_file_to_image(root->mlx, "sprite/wall/0.xpm", &w, &h);
    root->wall[1] = mlx_xpm_file_to_image(root->mlx, "sprite/wall/1.xpm", &w, &h);
    root->wall[2] = mlx_xpm_file_to_image(root->mlx, "sprite/wall/2.xpm", &w, &h);
    root->wall[3] = mlx_xpm_file_to_image(root->mlx, "sprite/wall/3.xpm", &w, &h);
    root->wall[4] = mlx_xpm_file_to_image(root->mlx, "sprite/wall/4.xpm", &w, &h);

    root->exit = mlx_xpm_file_to_image(root->mlx, "sprite/exit/0.xpm", &w, &h);
}