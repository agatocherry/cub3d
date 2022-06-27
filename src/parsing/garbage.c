/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:33:21 by agcolas           #+#    #+#             */
/*   Updated: 2022/06/27 15:31:28 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	texture_garbage(t_cub *cub, t_texture *texture)
{
	free(texture->no);
	free(texture->so);
	free(texture->we);
	free(texture->ea);
	if (cub->win_up == 1)
	{
		mlx_destroy_image(cub->mlx, texture->tex_img_no);
		mlx_destroy_image(cub->mlx, texture->tex_img_so);
		mlx_destroy_image(cub->mlx, texture->tex_img_we);
		mlx_destroy_image(cub->mlx, texture->tex_img_ea);
	}
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
	if (cub->win_up == 1)
	{
		mlx_destroy_window(cub->mlx, cub->mlx_win);
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
	}
}

int	end_loop(char *line, int fd)
{
	free(line);
	while (ft_gnl(fd, &line) > 0)
		free(line);
	return (1);
}
