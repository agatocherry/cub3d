/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:40:38 by agcolas           #+#    #+#             */
/*   Updated: 2022/07/05 13:36:17 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_extension(char *file, char *ext)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (file[i])
		i++;
	while (file[i] != '.')
		i--;
	if (file[i + 4] != '\n' && file[i + 4] != ' '
	    && file[i + 4] != '\0' && file[i + 4] != '\r')
		error++;
	if (ft_strncmp(&file[i], ext, 4) != 0)
		error++;
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Extension of the file is not ", 2);
		ft_putstr_fd(ext, 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	return (0);
}

static int	save_element(char *line, t_cub *cub)
{
	if (ft_strncmp(line, "F ", 2) == 0)
		if (color_f(line, &cub->color) == 1)
			return (1);
	if (ft_strncmp(line, "C ", 2) == 0)
		if (color_c(line, &cub->color) == 1)
			return (1);
	if (ft_strncmp(line, "NO ", 3) == 0)
		if (texture_no(line, &cub->tex) == 1)
			return (1);
	if (ft_strncmp(line, "SO ", 3) == 0)
		if (texture_so(line, &cub->tex) == 1)
			return (1);
	if (ft_strncmp(line, "WE ", 3) == 0)
		if (texture_we(line, &cub->tex) == 1)
			return (1);
	if (ft_strncmp(line, "EA ", 3) == 0)
		if (texture_ea(line, &cub->tex) == 1)
			return (1);
	return (0);
}

static int	read_line(int fd, t_cub *cub, char *file_name)
{
	char	*line;

	while (ft_gnl(fd, &line) > 0)
	{
		if (is_map(line, 0) == 0)
		{
			if (add_map(fd, file_name, cub, line) == 1)
				return (end_loop(line, fd));
			free(line);
			break ;
		}
		line = ft_one_sep(line, ' ');
		if (save_element(line, cub) == 1)
			return (end_loop(line, fd));
		free(line);
	}
	return (0);
}

static int	check_parsing(t_cub *cub)
{
	if (!cub->tex.no || !cub->tex.so
		|| !cub->tex.we || !cub->tex.ea)
		return (error_message("All textures are not defined"));
	if (cub->map == NULL)
		return (error_message("No map found"));
	if (cub->color.f == 0 || cub->color.c == 0)
		return (error_message("All colors are not defined"));
	cub->color.set = 1;
	return (0);
}

int	parsing(char *file_name, t_cub *cub)
{
	int		fd;

	init_parsing(cub);
	if (check_extension(file_name, ".cub") == 1)
		return (1);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (error_message(strerror(errno)));
	if (read_line(fd, cub, file_name) == 1)
		return (1);
	close(fd);
	if (check_parsing(cub) == 1)
		return (1);
	if (init_player(cub) == 1)
		return (1);
	return (0);
}
