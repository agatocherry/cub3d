#include "../../include/cub3d.h"

// This function adds a pixel of a given color at the x and y coordinates
void    my_pixel_put(t_data *img, int x, int y, int color)
{
    char    *dst;

    dst = img->addr + (y * img->line_l + x * (img->bpp / 8));
    *(unsigned int*)dst = color;
}

// This function should return the map width
int get_mapW(char **map)
{
    return (0);
}

// This function should return the map height
int get_mapH(char **map)
{
    return (0);
}