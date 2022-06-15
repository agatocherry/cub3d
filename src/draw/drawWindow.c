#include "../../include/cub3d.h"

void    draw_window(t_cub *cub)
{
    int col;

    col = 0;
    while (col < WIDTH)
    {
        cub->player.camera = 2 * col / (double)WIDTH - 1;
        get_rayparams(&cub->ray, &cub->player);
        get_rayhit(&cub->ray, cub->map);
        get_wallparams(&cub->ray, &cub->player, &cub->tex);
        draw_lines(col, &cub->ray, &cub->img, &cub->color);
        if (cub->player.left)
            moveleft(cub->map, &cub->player);
        if (cub->player.right)
            moveright(cub->map, &cub->player);
        if (cub->player.backwards)
            movebackward(cub->map, &cub->player);
        if (cub->player.forward)
            moveforward(cub->map, &cub->player);
        if (cub->player.rotleft)
            rotateleft(&cub->player);
        if (cub->player.rotright)
            rotateright(&cub->player);
        col++;
    }
}

// void    draw_window(t_cub *cub)
// {
//     int col = 0;
//     double w = WIDTH;

//     while (col < w)
//     {
//         pl->camera = 2 * col / w - 1;
//         ray->dir_x = pl->dir_x + pl->plane_x * pl->camera;
//         ray->dir_y = pl->dir_y + pl->plane_y * pl->camera;
//         ray->mapX = (int)pl->x;
//         ray->mapY = (int)pl->y;
//         if (ray->dir_x == 0)
//             ray->deltaDistX = 1e30;
//         else
//             ray->deltaDistX = fabs(1 / ray->dir_x);
//         if (ray->dir_y == 0)
//             ray->deltaDistY = 1e30;
//         else
//             ray->deltaDistY = fabs(1 / ray->dir_y);
//         ray->hit = 0;
//         if (ray->dir_x < 0)
//         {
//             ray->stepX = -1;
//             ray->sideDistX = (pl->x - ray->mapX) * ray->deltaDistX;
//         }
//         else
//         {
//             ray->stepX = 1;
//             ray->sideDistX = (ray->mapX + 1.0 - pl->x) * ray->deltaDistX;
//         }
//         if (ray->dir_y < 0)
//         {
//             ray->stepY = -1;
//             ray->sideDistY = (pl->y - ray->mapY) * ray->deltaDistY;
//         }
//         else
//         {
//             ray->stepY = 1;
//             ray->sideDistY = (ray->mapY + 1.0 - pl->y) * ray->deltaDistY;
//         }
//         while (ray->hit == 0)
//         {
//             if (ray->sideDistX < ray->sideDistY)
//             {
//                 ray->sideDistX += ray->deltaDistX;
//                 ray->mapX += ray->stepX;
//                 ray->side = 0;
//             }
//             else
//             {
//                 ray->sideDistY += ray->deltaDistY;
//                 ray->mapY += ray->stepY;
//                 ray->side = 1;
//             }
//             if (worldMap[ray->mapX][ray->mapY] > 0)
//                 ray->hit = 1;
//         }
//         if (ray->side == 0)
//         {
//             if (ray->mapX < pl->x)
//                 ray->wallDir = 'N';
//             else
//                 ray->wallDir = 'S';
//             ray->perpWallDist = (ray->sideDistX - ray->deltaDistX);
//             ray->wallX = pl->y + ray->perpWallDist * ray->dir_y;
//         }
//         else
//         {
//             if (ray->mapY < pl->y)
//                 ray->wallDir = 'W';
//             else
//                 ray->wallDir = 'E';
//             ray->perpWallDist = (ray->sideDistY - ray->deltaDistY);
//             ray->wallX = pl->x + ray->perpWallDist * ray->dir_x;
//         }
//         ray->wallX -= floor((ray->wallX));
        
//         int texX = (int)(ray->wallX * (double)TEXWIDTH);
//         if (ray->side == 0 && ray->dir_x > 0)
//             texX = TEXWIDTH - texX - 1;
//         if (ray->side == 1 && ray->dir_y < 0)
//             texX = TEXWIDTH - texX - 1;

//         int lineHeight = (int)(HEIGHT / ray->perpWallDist);
//         int drawStart = -lineHeight / 2 + HEIGHT / 2;
        
//         if (drawStart < 0)
//             drawStart = 0;
        
//         int drawEnd = lineHeight / 2 + HEIGHT / 2;
        
//         if (drawEnd >= HEIGHT)
//             drawEnd = HEIGHT - 1;
        
//         // int color = 0x0F56A414;

//         // if (ray->side == 1)
//         //     color = color / 2;
        
//         double step = 1.0 * TEXHEIGHT / lineHeight;
//         double texPos = (drawStart - HEIGHT / 2 + lineHeight / 2) * step;
        
//         int y = 0;
//         int color;
//         int texY;
//         char *dst;
//         int *text;
//         if (ray->wallDir == 'N')
//             text = tex->texNO;
//         else if (ray->wallDir == 'S')
//             text = tex->texSO;
//         else if (ray->wallDir == 'E')
//             text = tex->texEA;
//         else if (ray->wallDir == 'W')
//             text = tex->texWE;

//         while (y < drawStart)
//         {
//             dst = img->addr + (y * img->line_l + col * (img->bpp / 8));
//             *(unsigned int*)dst = 0x00070E97;
//             y++;
//         }
//         while (y < drawEnd)
//         {
//             dst = img->addr + (y * img->line_l + col * (img->bpp / 8));
//             texY = (int)texPos & (TEXHEIGHT - 1);
//             texPos += step;
//             color = text[TEXHEIGHT * texY + texX];
//             *(unsigned int*)dst = color;
//             y++;
//         }
//         while (y < HEIGHT)
//         {
//             dst = img->addr + (y * img->line_l + col * (img->bpp / 8));
//             *(unsigned int*)dst = 0x00FFDC4C;
//             y++;
//         }

//         if (pl->left)
//             moveleft(pl);
//         if (pl->right)
//             moveright(pl);
//         if (pl->backwards)
//             movebackward(pl);
//         if (pl->forward)
//             moveforward(pl);
//         if (pl->rotleft)
//             rotateleft(pl);
//         if (pl->rotright)
//             rotateright(pl);

//         col++;
//     }
// }
