/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:58:00 by agcolas           #+#    #+#             */
/*   Updated: 2022/06/23 11:58:00 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	set_rest(t_player *pl, char init_dir)
{
	if (init_dir == 'W')
	{
		pl->dir_x = 0;
		pl->dir_y = -1;
		pl->plane_x = -0.66;
		pl->plane_y = 0;
	}
	else
	{
		pl->dir_x = 0;
		pl->dir_y = 1;
		pl->plane_x = 0.66;
		pl->plane_y = 0;
	}
}

void	initial_dir(t_player *pl, char init_dir)
{
	if (init_dir == 'N')
	{
		pl->dir_x = -1;
		pl->dir_y = 0;
		pl->plane_x = 0;
		pl->plane_y = 0.66;
	}
	else if (init_dir == 'S')
	{
		pl->dir_x = 1;
		pl->dir_y = 0;
		pl->plane_x = -0.66;
		pl->plane_y = 0;
	}
	else
		set_rest(pl, init_dir);
}

static int	get_dir(char *dir, t_cub *cub, int j, int i)
{
	int	time;

	time = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S'
			|| cub->map[i][j] == 'W' || cub->map[i][j] == 'E')
			{
				cub->player.x = i;
				cub->player.y = j;
				*dir = cub->map[i][j];
				cub->map[i][j] = '0';
				time++;
			}
			j++;
		}
		i++;
	}
	if (time_error(time) == 1)
		return (1);
	return (0);
}

int	init_player(t_cub *cub)
{
	char	init_dir;

	if (get_dir(&init_dir, cub, 0, 0) == 1)
		return (1);
	initial_dir(&cub->player, init_dir);
	cub->player.camera = 0;
	cub->player.left = 0;
	cub->player.right = 0;
	cub->player.rotleft = 0;
	cub->player.rotright = 0;
	cub->player.forward = 0;
	cub->player.backwards = 0;
	return (0);
}

void	init_parsing(t_cub *cub)
{
	cub->map = NULL;
	cub->win_up = 0;
	cub->color.f = 0;
	cub->color.c = 0;
	cub->tex.so = NULL;
	cub->tex.no = NULL;
	cub->tex.we = NULL;
	cub->tex.ea = NULL;
}
