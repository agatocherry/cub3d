#include "../../include/cub3d.h"

void    rotateleft(t_player *pl)
{
    double  speed;
    double  oldDirX;
    double  oldPlaneX;

    speed = 0.0001;
    oldDirX = pl->dir_x;
    pl->dir_x = pl->dir_x * cos(speed) - pl->dir_y * sin(speed);
    pl->dir_y = oldDirX * sin(speed) + pl->dir_y * cos(speed);
    oldPlaneX = pl->plane_x;
    pl->plane_x = pl->plane_x * cos(speed) - pl->plane_y * sin(speed);
    pl->plane_y = oldPlaneX * sin(speed) + pl->plane_y * cos(speed);
}

void    rotateright(t_player *pl)
{
    double  speed;
    double  oldDirX;
    double  oldPlaneX;

    speed = 0.0001;
    oldDirX = pl->dir_x;
    pl->dir_x = pl->dir_x * cos(-speed) - pl->dir_y * sin(-speed);
    pl->dir_y = oldDirX * sin(-speed) + pl->dir_y * cos(-speed);
    oldPlaneX = pl->plane_x;
    pl->plane_x = pl->plane_x * cos(-speed) - pl->plane_y * sin(-speed);
    pl->plane_y = oldPlaneX * sin(-speed) + pl->plane_y * cos(-speed);
}