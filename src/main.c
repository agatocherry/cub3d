/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:33:21 by agcolas           #+#    #+#             */
/*   Updated: 2022/05/31 16:05:06 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** TODO : Tout ce qui est erreur est sortie 1
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
	//print_map(cub.map);
  	init_player(&cub); //-> This function gets the x and y coordinates of the player and its initial direction
	if (game_launch(&cub) == 1)
	{
		parsing_garbage(&cub);
		return (1);
	}
	parsing_garbage(&cub);
	return (0);
}
