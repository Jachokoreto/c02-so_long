#include "so_long.h"

void    draw_map(t_root *root)
{
    printf("hello from draw_map\n");
    int i;
    int j;

    int corner_x;
    int corner_y;

    // corner_x = 512 - ((64 * root->map_width) / 2);
    // corner_y = 384 - ((64 * root->map_height) / 2);
    corner_x = 512 - root->offset_x;
    corner_y = 384 - root->offset_y;

    printf("x: %d, y: %d\n", corner_x, corner_y);

    i = -1;
    while (++i < root->map_height)
    {
        j = -1;
        while (++j < root->map_width)
        {
            mlx_put_image_to_window(root->mlx, root->mlx_win, root->map_data[i][j][0],
                                    corner_x + (j * 64), corner_y + (i * 64));
            
            if (root->map_data[i][j][1] != NULL)
            {
                mlx_put_image_to_window(root->mlx, root->mlx_win, root->map_data[i][j][1],
                                        corner_x + (j * 64), corner_y + (i * 64));
            }
                
        }
    }
    mlx_put_image_to_window(root->mlx, root->mlx_win, root->player[0], 512, 384);

    // int w;
    // int h;
    // char *str = "./0.xpm";
    // void *img = mlx_xpm_file_to_image(root->mlx, str, &w, &h);
        
}
