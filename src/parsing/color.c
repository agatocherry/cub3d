/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:33:21 by agcolas           #+#    #+#             */
/*   Updated: 2022/06/23 12:10:44 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	char_to_rgb(char *color)
{
	int	i;
	int	red;
	int	green;
	int	blue;

	i = 0;
	while (color[i] && color[i] != ',')
		i++;
	red = ft_atoi(color);
	blue = ++i;
	while (color[i] && color[i] != ',')
		i++;
	green = ft_atoi(&color[blue]);
	blue = ft_atoi(&color[i + 1]);
	return (0 | red << 16 | green << 8 | blue);
}

static int	check_characters(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ',' && ft_isdigit(line[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	color_f(char *line, t_color *color)
{
	if (ft_strlen(line) <= 3)
		return (error_message("Color F is too short"));
	if (check_characters(&line[2]) == 1)
		return (error_message("Color F have incorrect syntax"));
	if (color->f != 0)
		return (error_message("Color F have multiple definition"));
	color->f = char_to_rgb(&line[2]);
	return (0);
}

int	color_c(char *line, t_color *color)
{
	if (ft_strlen(line) < 2)
		return (error_message("Color C is too short"));
	if (check_characters(&line[2]) == 1)
		return (error_message("Color C have incorrect syntax"));
	if (color->c != 0)
		return (error_message("Color C have multiple definition"));
	color->c = char_to_rgb(&line[2]);
	return (0);
}
