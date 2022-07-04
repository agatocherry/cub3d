/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:33:21 by agcolas           #+#    #+#             */
/*   Updated: 2022/07/04 17:47:41 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	is_map(char *line, int err)
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
		{
			if (err == 1)
			{
				ft_putstr_fd("Error\n", 2);
				ft_putstr_fd("There is an invalid character in map : ", 2);
				ft_putchar_fd(line[i], 2);
				ft_putstr_fd("\n", 2);
			}
			return (1);
		}
		i++;
	}
	if (ft_strcmp(line, "\n") == 0)
		return (1);
	return (0);
}

static void	fill_blank(char *to_fill, int size_max)
{
	int	len;

	len = ft_strlen(to_fill);
	while (len < size_max - 1)
	{
		to_fill[len] = ' ';
		len++;
	}
	to_fill[len] = '\0';
}

static void	replace_space(char **cub, int longest_char)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (cub[i])
	{
		j = 0;
		while (j < longest_char)
		{
			if (cub[i][j] == ' ')
				cub[i][j] = '1';
			j++;
		}
		i++;
	}
}

int	error_map(t_cub *cub, int longest_char)
{
	int	i;

	i = 0;
	while (cub->map[i])
	{
		if (is_map(cub->map[i], 1) == 1)
			return (1);
		i++;
	}
	if (check_walls(cub->map, longest_char) == 1)
		return (error_message("Map walls aren't closed"));
	replace_space(cub->map, longest_char);
	return (0);
}

int	time_error(int time)
{
	if (time > 1)
		return (error_message("Map have multiple start"));
	if (time == 0)
		return (error_message("Map do not have start"));
	return (0);
}
