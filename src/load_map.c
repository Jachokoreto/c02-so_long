#include "so_long.h"
#include <fcntl.h>

#include <stdio.h>

int check_map(char** map);

// get all the line in the .ber file and store in
// temporary string
void    load_map(void)
{
    int     fd;
    char**  map;
    char*   tmp;
    char*   str;
    
    fd = open("map.ber", O_RDONLY);
    str = ft_strdup("");
    while (1)
    {
        tmp = get_next_line(fd);
        printf("%s\n", tmp);

        if (!tmp)
            break; 
        str = ft_strjoin(str, tmp);

    }
        printf("str:%s\n", str);

    map = ft_split(str, '\n');

    if (map)
        printf("check map result: %d", check_map(map));
}

int check_map(char** map)
{
    char*   wall_to_check;
    int     i;
    int     right_wall;

    i = 0;
    wall_to_check = map[0];
    while (wall_to_check[i])
    {
        if (wall_to_check[i++] != '1')
        {
            printf("top wall is not 1: %d, %c\n", i-1, wall_to_check[i-1]);
            return 0;
        }
    }
    i = 1;
    while(map[i])
    {
        wall_to_check = map[i++];
        right_wall = ft_strlen(wall_to_check) - 1;
        if (wall_to_check[0] != '1' || wall_to_check[right_wall] != '1')
        {
            printf("left or right wall is not 1: %c, %c\n", wall_to_check[0], wall_to_check[right_wall]);
            return 0;
        }
    }
    
    while (wall_to_check[i])
    {
        if (wall_to_check[i++] != '1')
        {
            printf("bottom wall is not 1\n");
            return 0;
        }
    }

    return 1;
}

