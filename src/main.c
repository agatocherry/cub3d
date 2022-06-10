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

	if (argv[1] == NULL)
		return (error_message("Usage: ./cub3d [FILE].cub"));
	if (parsing(argv[1], &cub.file) == 1)
	{
		parsing_garbage(&cub.file);
		return (1);
	}
	print_map(cub.file.map);
	if (game_launch(&cub) == 1)
	{
		parsing_garbage(&cub.file);
		return (1);
	}
	parsing_garbage(&cub.file);
	return (0);
}
