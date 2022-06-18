/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shdorlin <shdorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:56:14 by shdorlin          #+#    #+#             */
/*   Updated: 2022/06/18 14:59:00 by shdorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_wallparams(t_ray *r, t_player *pl, t_texture *tex)
{
	if (r->side == 0)
	{
		if (r->map_x < pl->x)
			r->text = tex->tex_no;
		else
			r->text = tex->tex_so;
		r->perp_walldist = (r->side_distx - r->delta_distx);
		r->wallx = pl->y + r->perp_walldist * r->dir_y;
	}
	else
	{
		if (r->map_y < pl->y)
			r->text = tex->tex_we;
		else
			r->text = tex->tex_ea;
		r->perp_walldist = (r->side_disty - r->delta_disty);
		r->wallx = pl->x + r->perp_walldist * r->dir_x;
	}
	r->wallx -= floor((r->wallx));
}

void	get_rayhit(t_ray *r, char **map)
{
	r->hit = 0;
	while (r->hit == 0)
	{
		if (r->side_distx < r->side_disty)
		{
			r->side_distx += r->delta_distx;
			r->map_x += r->stepx;
			r->side = 0;
		}
		else
		{
			r->side_disty += r->delta_disty;
			r->map_y += r->stepy;
			r->side = 1;
		}
		if (map[r->map_x][r->map_y] == '1')
			r->hit = 1;
	}
}

void	get_raystep(t_ray *r, t_player *pl)
{
	if (r->dir_x < 0)
	{
		r->stepx = -1;
		r->side_distx = (pl->x - r->map_x) * r->delta_distx;
	}
	else
	{
		r->stepx = 1;
		r->side_distx = (r->map_x + 1.0 - pl->x) * r->delta_distx;
	}
	if (r->dir_y < 0)
	{
		r->stepy = -1;
		r->side_disty = (pl->y - r->map_y) * r->delta_disty;
	}
	else
	{
		r->stepy = 1;
		r->side_disty = (r->map_y + 1.0 - pl->y) * r->delta_disty;
	}
}

void	get_rayparams(t_ray *r, t_player *pl)
{
	r->dir_x = pl->dir_x + pl->plane_x * pl->camera;
	r->dir_y = pl->dir_y + pl->plane_y * pl->camera;
	r->map_x = (int)pl->x;
	r->map_y = (int)pl->y;
	r->delta_distx = fabs(1 / r->dir_x);
	r->delta_disty = fabs(1 / r->dir_y);
	r->hit = 0;
	get_raystep(r, pl);
}
