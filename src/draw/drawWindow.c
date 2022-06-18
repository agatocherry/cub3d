/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawWindow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shdorlin <shdorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:27:04 by shdorlin          #+#    #+#             */
/*   Updated: 2022/06/18 14:27:15 by shdorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_window(t_cub *cub)
{
	int	col;

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
