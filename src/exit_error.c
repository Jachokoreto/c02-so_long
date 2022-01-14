#include "so_long.h"

void    exit_error(char *msg, t_root *root, int state)
{
    int i;
    int j;

    if (state == 1)
    {
        perror(msg);
        exit(0);
    }
    else
        exit_game(root);
}