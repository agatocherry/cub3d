/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:33:21 by agcolas           #+#    #+#             */
/*   Updated: 2022/07/04 17:46:54 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static int	first_line(char **map)
{
	int	i;
	int	error;

	i = 0;
	while (map[0][i])
	{
		error = 1;
		if (map[0][i] == '1')
			error = 0;
		else if (map[0][i] == ' ' && map[1][i] && map[1][i] == '1')
			error = 0;
		if (error == 1)
			return (error_message("North wall map isn't closed"));
		i++;
	}
	return (0);
}

static int	first_char(char **map)
{
	int	i;
	int	error;

	i = 0;
	while (map[i] && map[i][0])
	{
		error = 1;
		if (map[i][0] == '1')
			error = 0;
		else if (map[i][0] == ' ' && map[i][1] && map[i][1] == '1')
			error = 0;
		if (error == 1)
			return (error_message("North wall map isn't closed"));
		i++;
	}
	return (0);
}

static int	last_char(char **map, int longest_char)
{
	int	i;
	int	j;
	int	error;

	i = 0;
	j = longest_char - 1;
	while (map[i] && map[i][j])
	{
		error = 1;
		if (map[i][j] == '1')
			error = 0;
		else if (map[i][j] == ' ' && map[i][j - 1] && map[i][j - 1] == '1')
			error = 0;
		if (error == 1)
			return (1);
		i++;
	}
	return (0);
}

static int	last_line(char **map)
{
	int	i;
	int	j;
	int	error;

	j = 0;
	while (map[j + 1])
		j++;
	i = 0;
	while (map[j][i])
	{
		error = 1;
		if (map[j][i] == '1')
			error = 0;
		else if (map[j][i] == ' ' && map[j - 1][i] && map[j - 1][i] == '1')
			error = 0;
		if (error == 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_walls(char **map, int longest_char)
{
	if (first_line(map) == 1)
		return (1);
	if (first_char(map) == 1)
		return (1);
	if (last_char(map, longest_char) == 1)
		return (1);
	if (last_line(map) == 1)
		return (1);
	return (0);
}
