/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:33:21 by agcolas           #+#    #+#             */
/*   Updated: 2022/05/31 16:05:06 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	mapsize(t_map *map)
{
	int	i;

	i = 0;
	while (map)
	{
		map = map->next;
		i++;
	}
	return (i);
}

t_map	*mapnew(char *line)
{
	t_map	*new;

	new = (t_map *)malloc(sizeof (t_map));
	if (new == NULL)
		return (NULL);
	new->line = line;
	new->next = NULL;
	return (new);
}

t_map	*maplast(t_map *map)
{
	if (!map)
		return (NULL);
	while (map->next)
		map = map->next;
	return (map);
}

void	mapadd_back(t_map **amap, t_map *lnew)
{
	t_map	*next;

	if (!amap || !lnew)
		return ;
	if (*amap)
	{
		next = maplast(*amap);
		next->next = lnew;
		return ;
	}
	*amap = lnew;
}
