/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shdorlin <shdorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:08:07 by shdorlin          #+#    #+#             */
/*   Updated: 2022/06/29 17:28:08 by shdorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rotateleft(t_player *pl)
{
	double	speed;
	double	old_dirx;
	double	old_planex;

	speed = 0.0001;
	old_dirx = pl->dir_x;
	pl->dir_x = pl->dir_x * cos(speed) - pl->dir_y * sin(speed);
	pl->dir_y = old_dirx * sin(speed) + pl->dir_y * cos(speed);
	old_planex = pl->plane_x;
	pl->plane_x = pl->plane_x * cos(speed) - pl->plane_y * sin(speed);
	pl->plane_y = old_planex * sin(speed) + pl->plane_y * cos(speed);
}

void	rotateright(t_player *pl)
{
	double	speed;
	double	old_dirx;
	double	old_planex;

	speed = 0.0001;
	old_dirx = pl->dir_x;
	pl->dir_x = pl->dir_x * cos(-speed) - pl->dir_y * sin(-speed);
	pl->dir_y = old_dirx * sin(-speed) + pl->dir_y * cos(-speed);
	old_planex = pl->plane_x;
	pl->plane_x = pl->plane_x * cos(-speed) - pl->plane_y * sin(-speed);
	pl->plane_y = old_planex * sin(-speed) + pl->plane_y * cos(-speed);
}
