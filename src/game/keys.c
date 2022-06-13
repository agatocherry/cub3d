#include "../../include/cub3d.h"

void    moveleft(t_player *pl)
{
    return ;
}

void    moveright(t_player *pl)
{
    return ;
}

void    moveforward(t_player *pl)
{
    if (worldMap[(int)(pl->x + pl->dir_x * pl->moveSpeed)][(int)pl->y] == 0)
        pl->x += pl->dir_x * pl->moveSpeed;
    if (worldMap[(int)pl->x][(int)(pl->y + pl->dir_y * pl->moveSpeed)] == 0)
        pl->y += pl->dir_y * pl->moveSpeed;
}

void    movebackward(t_player *pl)
{
    if (worldMap[(int)(pl->x - pl->dir_x * pl->moveSpeed)][(int)pl->y] == 0)
        pl->x -= pl->dir_x * pl->moveSpeed;
    if (worldMap[(int)pl->x][(int)(pl->y - pl->dir_y * pl->moveSpeed)] == 0)
        pl->y -= pl->dir_y * pl->moveSpeed;
}

void    rotateleft(t_player *pl)
{
    double oldDirX = pl->dir_x;
    pl->dir_x = pl->dir_x * cos(pl->rotSpeed) - pl->dir_y * sin(pl->rotSpeed);
    pl->dir_y = oldDirX * sin(pl->rotSpeed) + pl->dir_y * cos(pl->rotSpeed);
    double oldPlaneX = pl->plane_x;
    pl->plane_x = pl->plane_x * cos(pl->rotSpeed) - pl->plane_y * sin(pl->rotSpeed);
    pl->plane_y = oldPlaneX * sin(pl->rotSpeed) + pl->plane_y * cos(pl->rotSpeed);
}

void    rotateright(t_player *pl)
{
    double oldDirX = pl->dir_x;
    pl->dir_x = pl->dir_x * cos(-pl->rotSpeed) - pl->dir_y * sin(-pl->rotSpeed);
    pl->dir_y = oldDirX * sin(-pl->rotSpeed) + pl->dir_y * cos(-pl->rotSpeed);
    double oldPlaneX = pl->plane_x;
    pl->plane_x = pl->plane_x * cos(-pl->rotSpeed) - pl->plane_y * sin(-pl->rotSpeed);
    pl->plane_y = oldPlaneX * sin(-pl->rotSpeed) + pl->plane_y * cos(-pl->rotSpeed);
}
