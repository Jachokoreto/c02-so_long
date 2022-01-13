#include "so_long.h"

void    destroy_images(t_root *root, void **array, int size);

int    exit_game(t_root *root)
{
    int i;
    int j;

    destroy_images(root, root->grass, 3);
    destroy_images(root, &root->collectible, 1);
    destroy_images(root, root->player, 4);
    destroy_images(root, root->wall, 5);
    destroy_images(root, &root->exit, 1);

    i = -1;
    while (root->map[++i])
        free(root->map[i]);
    // free(root->map);

    i = -1;
    while (root->map_data[++i])
    {
        j = -1;
        while (root->map_data[i][++j])
        {
            free(root->map_data[i][j]);
        }
        free(root->map_data[i]);
    }
    // free(root->map_data);

    mlx_destroy_window(root->mlx, root->mlx_win);
    // free(root->mlx);
    // free(root->mlx_win);
    exit(0);
}

void    destroy_images(t_root *root, void **array, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        mlx_destroy_image(root->mlx, array[i]);
        i++;
    }
}