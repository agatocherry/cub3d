#include "../../include/cub3d.h"

void    draw_ceiling(t_data *img, int stop, int col, t_color *c)
{
    int     y;
    char    *dst;

    y = 0;
    while (y < stop)
    {
        dst = img->addr + (y * img->line_l + col * (img->bpp / 8));
        *(unsigned int*)dst = c->c;
        y++;
    }
}

void    draw_floor(t_data *img, int begin, int col, t_color *c)
{
    char    *dst;

    while (begin < HEIGHT)
    {
        dst = img->addr + (begin * img->line_l + col * (img->bpp / 8));
        *(unsigned int*)dst = c->f;
        begin++;
    } 
}

void    draw_texture(t_data *img, t_ray *r, int col, int texX)
{
    int     y;
    int     texY;
    double  step;
    double  texPos;
    char    *dst;

    y = -((int)(HEIGHT / r->perpWallDist)) / 2 + HEIGHT / 2;
    if (y < 0)
        y = 0;
    step = 1.0 * TEXHEIGHT / ((int)(HEIGHT / r->perpWallDist));
    texPos = (y - HEIGHT / 2 + ((int)(HEIGHT / r->perpWallDist)) / 2) * step;
    while (y < (((int)(HEIGHT / r->perpWallDist)) / 2 + HEIGHT / 2))
    {
        dst = img->addr + (y * img->line_l + col * (img->bpp / 8));
        texY = (int)texPos & (TEXHEIGHT - 1);
        texPos += step;
        *(unsigned int*)dst = r->text[TEXHEIGHT * texY + texX];
        y++;
        if (y == HEIGHT)
            return ;
    }
}

void    draw_lines(int col, t_ray *r, t_data *img, t_color *c)
{
    int texX;
    int drawStart;
    int drawEnd;
    int lineHeight;

    texX = (int)(r->wallX * (double)TEXWIDTH);
    if (r->side == 0 && r->dir_x > 0)
        texX = TEXWIDTH - texX - 1;
    if (r->side == 1 && r->dir_y < 0)
        texX = TEXWIDTH - texX - 1;
    lineHeight = (int)(HEIGHT / r->perpWallDist);
    drawStart = -lineHeight / 2 + HEIGHT / 2;
    if (drawStart < 0)
        drawStart = 0;
    drawEnd = lineHeight / 2 + HEIGHT / 2;
    if (drawEnd >= HEIGHT)
        drawEnd = HEIGHT - 1;
    draw_ceiling(img, drawStart, col, c);
    draw_texture(img, r, col, texX);
    draw_floor(img, drawEnd, col, c);
}