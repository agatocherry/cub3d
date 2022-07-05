/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:33:21 by agcolas           #+#    #+#             */
/*   Updated: 2022/07/05 13:46:55 by agcolas          ###   ########.fr       */
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
		else if (map[0][i] == ' ')
		{
			int j = 0;
			while (map[j][i] == ' ')
				j++;
			if (map[j][i] == '1')
				error = 0;
		}
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
		else if (map[i][0] == ' ')
		{
			int j = 0;
			while (map[i][j] == ' ')
				j++;
			if (map[i][j] == '1')
				error = 0;
		}
		if (error == 1)
			return (error_message("West wall map isn't closed"));
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
		else if (map[i][j] == ' ')
		{
			int k = j;
			while (map[i][k] == ' ')
				k--;
			if (map[i][k] == '1')
				error = 0;
		}
		if (error == 1)
			return (error_message("East map wall isn't closed"));
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
		else if (map[j][i] == ' ')
		{
			int k = j;
			while (map[k][i] == ' ')
				k--;
			if (map[k][i] == '1')
				error = 0;
		}
		if (error == 1)
			return (error_message("South map wall isn't closed"));
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
