/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shdorlin <shdorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:05:04 by shdorlin          #+#    #+#             */
/*   Updated: 2022/06/18 15:07:53 by shdorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	moveleft(char **map, t_player *pl)
{
	double	speed;

	speed = 0.0002;
	if (map[(int)(pl->x)][(int)(pl->y + pl->dir_x * speed)] == '0')
		pl->y += pl->dir_x * speed;
	if (map[(int)(pl->x - pl->dir_y * speed)][(int)(pl->y)] == '0')
		pl->x -= pl->dir_y * speed;
}

void	moveright(char **map, t_player *pl)
{
	double	speed;

	speed = 0.0002;
	if (map[(int)(pl->x)][(int)(pl->y - pl->dir_x * speed)] == '0')
		pl->y -= pl->dir_x * speed;
	if (map[(int)(pl->x - pl->dir_y * speed)][(int)(pl->y)] == '0')
		pl->x += pl->dir_y * speed;
}

void	moveforward(char **map, t_player *pl)
{
	double	speed;

	speed = 0.0002;
	if (map[(int)(pl->x + pl->dir_x * speed)][(int)(pl->y)] == '0')
		pl->x += pl->dir_x * speed;
	if (map[(int)(pl->x)][(int)(pl->y + pl->dir_y * speed)] == '0')
		pl->y += pl->dir_y * speed;
}

void	movebackward(char **map, t_player *pl)
{
	double	speed;

	speed = 0.0002;
	if (map[(int)(pl->x - pl->dir_x * speed)][(int)(pl->y)] == '0')
		pl->x -= pl->dir_x * speed;
	if (map[(int)(pl->x)][(int)(pl->y - pl->dir_y * speed)] == '0')
		pl->y -= pl->dir_y * speed;
}
