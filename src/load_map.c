#include "so_long.h"
#include <fcntl.h>

#include <stdio.h>

// get all the line in the .ber file and store in
// temporary string
void    load_map(void)
{

    int fd;
    
    fd = open("map.ber", O_RDONLY);

    char*   str;
    char*   tmp;
    
    str = get_next_line(fd);

    while (str)
    {
        
        tmp = get_next_line(fd);
        if (tmp)
            str = ft_strjoin(str, tmp);
        else
            break;    
    }

    char** map;

    map = ft_split(str, '\n');

    int i = 0;
    while (map[i])
        printf("%s\n", map[i++]);
}

