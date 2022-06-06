/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:33:21 by agcolas           #+#    #+#             */
/*   Updated: 2022/05/31 16:05:06 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	color_f(char *line, t_color *color)
{
	if (ft_strlen(line) > 2)
	{
		if (color->f)
			free(color->f);
		color->f = ft_substr(line, 2, ft_strlen(line) - 3);
	}
	printf("Color F [%s]\n", color->f);
}

void	color_c(char *line, t_color *color)
{
	if (ft_strlen(line) > 2)
	{
		if (color->c)
			free(color->c);
		color->c = ft_substr(line, 2, ft_strlen(line) - 3);
	}
	printf("Color C [%s]\n", color->c);
}
