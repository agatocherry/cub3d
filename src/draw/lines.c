/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shdorlin <shdorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:35:33 by shdorlin          #+#    #+#             */
/*   Updated: 2022/06/18 14:40:42 by shdorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_ceiling(t_data *img, int stop, int col, t_color *c)
{
	int		y;
	char	*dst;

	y = 0;
	while (y < stop)
	{
		dst = img->addr + (y * img->line_l + col * (img->bpp / 8));
		*(unsigned int *)dst = c->c;
		y++;
	}
}

void	draw_floor(t_data *img, int begin, int col, t_color *c)
{
	char	*dst;

	while (begin < HEIGHT)
	{
		dst = img->addr + (begin * img->line_l + col * (img->bpp / 8));
		*(unsigned int *)dst = c->f;
		begin++;
	}
}

void	draw_texture(t_data *img, t_ray *r, int col, int tex_x)
{
	int		y;
	int		tex_y;
	double	step;
	double	tex_pos;
	char	*dst;

	y = -((int)(HEIGHT / r->perp_walldist)) / 2 + HEIGHT / 2;
	if (y < 0)
		y = 0;
	step = 1.0 * TEXHEIGHT / ((int)(HEIGHT / r->perp_walldist));
	tex_pos = (y - (int)HEIGHT / 2 + ((int)(HEIGHT / r->perp_walldist)) / 2)
		* step;
	while (y < (((int)(HEIGHT / r->perp_walldist)) / 2 + HEIGHT / 2))
	{
		dst = img->addr + (y * img->line_l + col * (img->bpp / 8));
		tex_y = (int)tex_pos & (TEXHEIGHT - 1);
		tex_pos += step;
		*(unsigned int *)dst = *(r->text + TEXHEIGHT * tex_y + tex_x);
		y++;
		if (y == HEIGHT)
			return ;
	}
}

void	draw_lines(int col, t_ray *r, t_data *img, t_color *c)
{
	int	tex_x;
	int	draw_start;
	int	draw_end;
	int	line_h;

	tex_x = (int)(r->wallx * (double)TEXWIDTH);
	if (r->side == 0 && r->dir_x > 0)
		tex_x = TEXWIDTH - tex_x - 1;
	if (r->side == 1 && r->dir_y < 0)
		tex_x = TEXWIDTH - tex_x - 1;
	line_h = (int)(HEIGHT / r->perp_walldist);
	draw_start = (-1 * line_h) / 2 + HEIGHT / 2;
	if (draw_start < 0 || draw_start >= HEIGHT)
		draw_start = 0;
	draw_end = line_h / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT || draw_end < 0)
		draw_end = HEIGHT - 1;
	draw_ceiling(img, draw_start, col, c);
	draw_texture(img, r, col, tex_x);
	draw_floor(img, draw_end, col, c);
}
