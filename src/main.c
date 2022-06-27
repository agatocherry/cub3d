/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:33:21 by agcolas           #+#    #+#             */
/*   Updated: 2022/06/27 15:37:34 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
static void print_parsing(t_cub *cub)
{
	int	i;

	i = 0;
	printf("Color F [%d]\n", cub->color.f);
	printf("Color C [%d]\n", cub->color.c);
	printf("Texture NO [%s]\n", cub->tex.no);
	printf("Texture SO [%s]\n", cub->tex.so);
	printf("Texture WE [%s]\n", cub->tex.we);
	printf("Texture EA [%s]\n", cub->tex.ea);
	if (cub->map)
		while (cub->map[i])
		{
			printf("Map %d [%s]\n", i, cub->map[i]);
			i++;
		}
	printf("Position X [%f]\n", cub->player.x);
	printf("Position Y [%f]\n", cub->player.y);
}

	print_parsing(&cub);
*/

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (argc != 2)
		return (error_message("Usage: ./cub3d [FILE].cub"));
	cub.tex = (t_texture){0};
	cub.img = (t_data){0};
	cub.minimap = (t_data){0};
	cub.color = (t_color){0};
	if (parsing(argv[1], &cub) == 1)
	{
		parsing_garbage(&cub);
		return (1);
	}
	if (game_launch(&cub) == 1)
	{
		parsing_garbage(&cub);
		return (1);
	}
	parsing_garbage(&cub);
	return (0);
}
