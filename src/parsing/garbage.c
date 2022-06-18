/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:33:21 by agcolas           #+#    #+#             */
/*   Updated: 2022/05/31 16:05:06 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	texture_garbage(t_cub *cub, t_texture *texture)
{
	free(texture->no);
	free(texture->so);
	free(texture->we);
	free(texture->ea);
	mlx_destroy_image(cub->mlx, texture->tex_imgNO);
	mlx_destroy_image(cub->mlx, texture->tex_imgSO);
	mlx_destroy_image(cub->mlx, texture->tex_imgWE);
	mlx_destroy_image(cub->mlx, texture->tex_imgEA);
}

void	mapclear(char **map)
{
	int	i;

	i = -1;
	if (!map)
		return ;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	cleardata(t_data *data)
{
	if (data->img)
		free(data->img);
	if (data->addr)
		free(data->addr);
}

void	parsing_garbage(t_cub *cub)
{
	texture_garbage(cub, &cub->tex);
	mapclear(cub->map);
	cleardata(&cub->minimap);
	mlx_destroy_window(cub->mlx, cub->mlx_win);
	mlx_destroy_display(cub->mlx);
	free(cub->mlx);
}
