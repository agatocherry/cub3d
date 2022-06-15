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

static void	texture_garbage(t_texture *texture)
{
	free(texture->no);
	free(texture->so);
	free(texture->we);
	free(texture->ea);
	free(texture->tex_imgNO);
	free(texture->tex_imgSO);
	free(texture->tex_imgWE);
	free(texture->tex_imgEA);
	free(texture->texNO);
	free(texture->texSO);
	free(texture->texWE);
	free(texture->texEA);
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
	free(data->img);
	free(data->addr);
}

void	parsing_garbage(t_cub *cub)
{
	texture_garbage(&cub->tex);
	mapclear(cub->map);
	cleardata(&cub->img);
	cleardata(&cub->minimap);
	free(cub->mlx);
	free(cub->mlx_win);
}
