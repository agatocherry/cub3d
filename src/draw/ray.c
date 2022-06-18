#include "../../include/cub3d.h"

void    get_wallparams(t_ray *r, t_player *pl, t_texture *tex)
{
    if (r->side == 0)
    {
        if (r->mapX < pl->x)
            r->text = tex->texNO;
        else
            r->text = tex->texSO;
        // r->perpWallDist = (r->sideDistX - r->deltaDistX);
        r->perpWallDist = (r->mapX - pl->x + (1 - r->stepX) / 2) / r->dir_x;
        r->wallX = pl->y + r->perpWallDist * r->dir_y;
    }
    else
    {
        if (r->mapY < pl->y)
            r->text = tex->texWE;
        else
            r->text = tex->texEA;
        r->perpWallDist = (r->mapY - pl->y + (1 - r->stepY) / 2) / r->dir_y;
        // r->perpWallDist = (r->sideDistY - r->deltaDistY);
        r->wallX = pl->x + r->perpWallDist * r->dir_x;
    }
    r->wallX -= floor((r->wallX));
}

void    get_rayhit(t_ray *r, char **map)
{
    r->hit = 0;
    while (r->hit == 0)
    {
        if (r->sideDistX < r->sideDistY)
        {
            r->sideDistX += r->deltaDistX;
            r->mapX += r->stepX;
            r->side = 0;
        }
        else
        {
            r->sideDistY += r->deltaDistY;
            r->mapY += r->stepY;
            r->side = 1;
        }
        if (map[r->mapX][r->mapY] == '1')
            r->hit = 1;
    }
}

void    get_raystep(t_ray *r, t_player *pl)
{
    if (r->dir_x < 0)
    {
        r->stepX = -1;
        r->sideDistX = (pl->x - r->mapX) * r->deltaDistX;
    }
    else
    {
        r->stepX = 1;
        r->sideDistX = (r->mapX + 1.0 - pl->x) * r->deltaDistX;
    }
    if (r->dir_y < 0)
    {
        r->stepY = -1;
        r->sideDistY = (pl->y - r->mapY) * r->deltaDistY;
    }
    else
    {
        r->stepY = 1;
        r->sideDistY = (r->mapY + 1.0 - pl->y) * r->deltaDistY;
    }
}

void    get_rayparams(t_ray *r, t_player *pl)
{
    r->dir_x = pl->dir_x + pl->plane_x * pl->camera;
    r->dir_y = pl->dir_y + pl->plane_y * pl->camera;
    r->mapX = (int)pl->x;
    r->mapY = (int)pl->y;
    r->deltaDistX = fabs(1 / r->dir_x);
    r->deltaDistY = fabs(1 / r->dir_y);
    r->hit = 0;
    get_raystep(r, pl);
}