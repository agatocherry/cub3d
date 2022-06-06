/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:31:20 by agcolas           #+#    #+#             */
/*   Updated: 2022/05/31 16:05:06 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*
** TODO : Ne pas utiliser gnl, trop lent
*/

static int	save(char *line, t_file *file, int nb_line)
{
	if (ft_strncmp(line, "F", 1) == 0)
		color_f(line, &file->color);
	if (ft_strncmp(line, "C", 1) == 0)
		color_c(line, &file->color);
	if (ft_strncmp(line, "NO", 2) == 0)
		texture_no(line, &file->texture);
	if (ft_strncmp(line, "SO", 2) == 0)
		texture_so(line, &file->texture);
	if (ft_strncmp(line, "WE", 2) == 0)
		texture_we(line, &file->texture);
	if (ft_strncmp(line, "EA", 2) == 0)
		texture_ea(line, &file->texture);
	if (nb_line >= 1)
		nb_line++;
	if (is_map(line) == 0)
	{
		if (nb_line <= mapsize(file->map) + 1)
			map(line, file);
		if (nb_line == 0)
			nb_line++;
	}
	return (nb_line);
}

int	error_infos(t_file *file)
{
	int	error;

	error = 0;
	if (!file->texture.no || !file->texture.so
		|| !file->texture.we || !file->texture.ea)
		error = 1;
	if (!file->color.f || !file->color.c)
	{
		if (error == 0)
			return (error_message("Miss color info"));
		else
			return (error_message("Miss texture and color info"));
	}
	if (error == 1)
		return (error_message("Miss texture info"));
	if (mapsize(file->map) == 0)
		return (error_message("Miss map info"));
	return (0);
}

int	parsing(char *file_name, t_file *file)
{
	int		fd;
	char	*line;
	int		nb_line;

	*file = (t_file){0};
	nb_line = 0;
	if (error_file(file_name) == 1)
		return (1);
	fd = open(file_name, O_APPEND);
	if (fd == -1)
		return (error_message(strerror(errno)));
	while (ft_gnl(fd, &line) > 0)
	{
		nb_line = save(line, file, nb_line);
		free(line);
	}
	close(fd);
	if (error_infos(file) == 1)
		return (1);
	if (error_map(file->map) == 1)
		return (1);
	return (0);
}
