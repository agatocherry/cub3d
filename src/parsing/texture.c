/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:33:21 by agcolas           #+#    #+#             */
/*   Updated: 2022/05/31 16:05:06 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	texture_no(char *line, t_texture *texture)
{
	if (ft_strlen(line) > 3)
	{
		if (texture->no)
			free(texture->no);
		texture->no = ft_substr(line, 3, ft_strlen(line) - 4);
	}
	printf("Texture NO [%s]\n", texture->no);
}

void	texture_so(char *line, t_texture *texture)
{
	if (ft_strlen(line) > 3)
	{
		if (texture->so)
			free(texture->so);
		texture->so = ft_substr(line, 3, ft_strlen(line) - 4);
	}
	printf("Texture SO [%s]\n", texture->so);
}

void	texture_we(char *line, t_texture *texture)
{
	if (ft_strlen(line) > 3)
	{
		if (texture->we)
			free(texture->we);
		texture->we = ft_substr(line, 3, ft_strlen(line) - 4);
	}
	printf("Texture WE [%s]\n", texture->we);
}

void	texture_ea(char *line, t_texture *texture)
{
	if (ft_strlen(line) > 3)
	{
		if (texture->ea)
			free(texture->ea);
		texture->ea = ft_substr(line, 3, ft_strlen(line) - 4);
	}
	printf("Texture EA [%s]\n", texture->ea);
}
