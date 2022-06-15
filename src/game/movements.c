#include "../../include/cub3d.h"

void    moveleft(char **map, t_player *pl)
{
    double speed = 0.0002;
    
    if (map[(int)(pl->x)][(int)(pl->y + pl->dir_x * speed)] == '0')
        pl->y += pl->dir_x * speed;
    if (map[(int)(pl->x - pl->dir_y * speed)][(int)(pl->y)] == '0')
        pl->x -= pl->dir_y * speed;
}

void    moveright(char **map, t_player *pl)
{
    double speed = 0.0002;
 
    if (map[(int)(pl->x)][(int)(pl->y - pl->dir_x * speed)] == '0')
        pl->y -= pl->dir_x * speed;
    if (map[(int)(pl->x - pl->dir_y * speed)][(int)(pl->y)] == '0')
        pl->x += pl->dir_y * speed;
}

void    moveforward(char **map, t_player *pl)
{
    double speed = 0.0002;
 
    if (map[(int)(pl->x + pl->dir_x * speed)][(int)(pl->y)] == '0')
        pl->x += pl->dir_x * speed;
    if (map[(int)(pl->x)][(int)(pl->y + pl->dir_y * speed)] == '0')
        pl->y += pl->dir_y * speed;
}

void    movebackward(char **map, t_player *pl)
{
    double speed = 0.0002;
 
    if (map[(int)(pl->x - pl->dir_x * speed)][(int)(pl->y)] == '0')
        pl->x -= pl->dir_x * speed;
    if (map[(int)(pl->x)][(int)(pl->y - pl->dir_y * speed)] == '0')
        pl->y -= pl->dir_y * speed;
}