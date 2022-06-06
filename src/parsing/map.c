/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:33:21 by agcolas           #+#    #+#             */
/*   Updated: 2022/05/31 16:05:06 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'W' && line[i] != 'E'
			&& line[i] != '\n' && line[i] != ' '
			&& line[i] != EOF)
			return (1);
		i++;
	}
	if (ft_strcmp(line, "\n") == 0)
		return (1);
	return (0);
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (map)
	{
		printf("Map %i [%s]\n", i, map->line);
		map = map->next;
		i++;
	}
}

void	map(char *line, t_file *file)
{
	mapadd_back(&file->map, mapnew(ft_substr(line, 0, ft_strlen(line) - 1)));
}
