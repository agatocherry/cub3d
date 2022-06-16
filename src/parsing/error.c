/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:33:21 by agcolas           #+#    #+#             */
/*   Updated: 2022/05/31 16:05:06 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	error_message(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int	error_file(char *file)
{
	int	i;

	i = 0;
	while (file[i] && file[i] != '.')
		i++;
	if (i == ft_strlen(file))
		return (error_message("Extension of the file is not .cub"));
	if (ft_strcmp(&file[i], ".cub") != 0)
		return (error_message("Extension of the file is not .cub"));
	return (0);
}

// static int	check_spawn(t_map *map)
// {
// 	int	total;
// 	int	i;

// 	total = 0;
// 	while (map)
// 	{
// 		i = 0;
// 		while (map->line[i])
// 		{
// 			if (map->line[i] == 'N' || map->line[i] == 'S'
// 				|| map->line[i] == 'E' || map->line[i] == 'W')
// 				total++;
// 			i++;
// 		}
// 		map = map->next;
// 	}
// 	return (total);
// }

// static int	check_wall(t_map *map)
// {
// 	int	i;
// 	int	len;

// 	len = 0;
// 	while (map)
// 	{
// 		if (map->line[0] != '1')
// 			return (1);
// 		if (map->line[ft_strlen(map->line) - 1] != '1')
// 			return (1);
// 		if (len == 0 || !map->next)
// 		{
// 			i = 0;
// 			while (map->line[i])
// 			{
// 				if (map->line[i] != '1' && map->line[i] != ' ')
// 					return (1);
// 				i++;
// 			}
// 		}
// 		map = map->next;
// 		len++;
// 	}
// 	return (0);
// }

// int	error_map(t_map *map)
// {
// 	if (check_spawn(map) > 1)
// 		return (error_message("The map must have one start position"));
// 	if (check_wall(map) == 1)
// 		return (error_message("The map must be closed by walls"));
// 	return (0);
// }
