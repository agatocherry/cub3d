#include "../../include/cub3d.h"

void    draw_line(int col, int start, int end, t_data *img, int color)
{
    char    *dst;
    int     y = start;

    while (y < end)
    {
        dst = img->addr + (y * img->line_l + col * (img->bpp / 8));
        *(unsigned int*)dst = color;
        y++;
    }
}

void    draw_window(t_player *pl, t_data *img, t_ray *ray)
{
    int col = 0;
    int width = 640;
    int height = 480;

    while (col < width)
    {
        pl->camera = 2 * col / (double)width - 1;
        ray->dir_x = pl->dir_x + pl->plane_x * pl->camera;
        ray->dir_y = pl->dir_y + pl->plane_y * pl->camera;
        ray->mapX = (int)pl->x;
        ray->mapY = (int)pl->y;
        if (ray->dir_x == 0)
            ray->deltaDistX = 1e30;
        else
            ray->deltaDistX = fabs(1 / ray->dir_x);
        if (ray->dir_y == 0)
            ray->deltaDistY = 1e30;
        else
            ray->deltaDistY = fabs(1 / ray->dir_y);
        ray->hit = 0;
        if (ray->dir_x < 0)
        {
            ray->stepX = -1;
            ray->sideDistX = (pl->x - ray->mapX) * ray->deltaDistX;
        }
        else
        {
            ray->stepX = 1;
            ray->sideDistX = (ray->mapX + 1.0 - pl->x) * ray->deltaDistX;
        }
        if (ray->dir_y < 0)
        {
            ray->stepY = -1;
            ray->sideDistY = (pl->y - ray->mapY) * ray->deltaDistY;
        }
        else
        {
            ray->stepY = 1;
            ray->sideDistY = (ray->mapY + 1.0 - pl->y) * ray->deltaDistY;
        }
        while (ray->hit == 0)
        {
            if (ray->sideDistX < ray->sideDistY)
            {
                ray->sideDistX += ray->deltaDistX;
                ray->mapX += ray->stepX;
                ray->side = 0;
            }
            else
            {
                ray->sideDistY += ray->deltaDistY;
                ray->mapY += ray->stepY;
                ray->side = 1;
            }
            if (worldMap[ray->mapX][ray->mapY] > 0)
                ray->hit = 1;
        }
        if (ray->side == 0)
            ray->perpWallDist = (ray->sideDistX - ray->deltaDistX);
        else
            ray->perpWallDist = (ray->sideDistY - ray->deltaDistY);
        
        int lineHeight = (int)(height / ray->perpWallDist);
        int drawStart = -lineHeight / 2 + height / 2;
        
        if (drawStart < 0)
            drawStart = 0;
        
        int drawEnd = lineHeight / 2 + height / 2;
        
        if (drawEnd >= height)
            drawEnd = height - 1;
        
        int color = 0x0F56A414;

        if (ray->side == 1)
            color = color / 2;
        
        draw_line(col, drawStart, drawEnd, img, color);
        if (pl->left)
            moveleft(pl);
        if (pl->right)
            moveright(pl);
        if (pl->backwards)
            movebackward(pl);
        if (pl->forward)
            moveforward(pl);
        if (pl->rotleft)
            rotateleft(pl);
        if (pl->rotright)
            rotateright(pl);

        col++;
    }
}
