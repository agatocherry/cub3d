#include "../../include/cub3d.h"

void    moveleft(t_player *pl)
{
    if (worldMap[(int)(pl->x)][(int)(pl->y + pl->dir_x * 0.0002)] == 0)
        pl->y += pl->dir_x * 0.0002;
    if (worldMap[(int)(pl->x - pl->dir_y * 0.0002)][(int)(pl->y)] == 0)
        pl->x -= pl->dir_y * 0.0002;
}

void    moveright(t_player *pl)
{
    if (worldMap[(int)(pl->x)][(int)(pl->y - pl->dir_x * 0.0002)] == 0)
        pl->y -= pl->dir_x * 0.0002;
    if (worldMap[(int)(pl->x - pl->dir_y * 0.0002)][(int)(pl->y)] == 0)
        pl->x += pl->dir_y * 0.0002;
}

void    moveforward(t_player *pl)
{
    if (worldMap[(int)(pl->x + pl->dir_x * 0.0002)][(int)(pl->y)] == 0)
        pl->x += pl->dir_x * 0.0002;
    if (worldMap[(int)(pl->x)][(int)(pl->y + pl->dir_y * 0.0002)] == 0)
        pl->y += pl->dir_y * 0.0002;
}

void    movebackward(t_player *pl)
{
    if (worldMap[(int)(pl->x - pl->dir_x * 0.0002)][(int)(pl->y)] == 0)
        pl->x -= pl->dir_x * 0.0002;
    if (worldMap[(int)(pl->x)][(int)(pl->y - pl->dir_y * 0.0002)] == 0)
        pl->y -= pl->dir_y * 0.0002;
}

void    rotateleft(t_player *pl)
{
    double oldDirX = pl->dir_x;
    pl->dir_x = pl->dir_x * cos(0.0002) - pl->dir_y * sin(0.0002);
    pl->dir_y = oldDirX * sin(0.0002) + pl->dir_y * cos(0.0002);
    double oldPlaneX = pl->plane_x;
    pl->plane_x = pl->plane_x * cos(0.0002) - pl->plane_y * sin(0.0002);
    pl->plane_y = oldPlaneX * sin(0.0002) + pl->plane_y * cos(0.0002);
}

void    rotateright(t_player *pl)
{
    double oldDirX = pl->dir_x;
    pl->dir_x = pl->dir_x * cos(-0.0002) - pl->dir_y * sin(-0.0002);
    pl->dir_y = oldDirX * sin(-0.0002) + pl->dir_y * cos(-0.0002);
    double oldPlaneX = pl->plane_x;
    pl->plane_x = pl->plane_x * cos(-0.0002) - pl->plane_y * sin(-0.0002);
    pl->plane_y = oldPlaneX * sin(-0.0002) + pl->plane_y * cos(-0.0002);
}
