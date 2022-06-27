/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:33:21 by agcolas           #+#    #+#             */
/*   Updated: 2022/06/23 12:13:34 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_sixty_four(char *file)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (error_message(strerror(errno)));
	while (ft_gnl(fd, &line) > 0)
	{
		if (i == 2)
			break ;
		free(line);
		i++;
	}
	close(fd);
	if (ft_strncmp(line, "\"64 64 ", 7) != 0)
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}

int	texture_no(char *line, t_texture *texture)
{
	int	fd;

	if (ft_strlen(line) <= 4)
		return (error_message("Texture NO is too short"));
	if (check_extension(&line[3], ".xpm\n") == 1)
		return (1);
	if (texture->no != NULL)
		return (error_message("Texture NO have multiple definition"));
	texture->no = ft_substr(line, 3, ft_strlen(line) - 4);
	fd = open(texture->no, O_RDONLY | O_WRONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nNo such file or directory: ", 2);
		ft_putstr_fd(texture->no, 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	close (fd);
	if (check_sixty_four(texture->no) == 1)
		return (error_message("Texture NO does not have 64*64 format"));
	return (0);
}

int	texture_so(char *line, t_texture *texture)
{
	int	fd;

	if (ft_strlen(line) <= 4)
		return (error_message("Texture SO is too short"));
	if (check_extension(&line[3], ".xpm\n") == 1)
		return (1);
	if (texture->so != NULL)
		return (error_message("Texture SO have multiple definition"));
	texture->so = ft_substr(line, 3, ft_strlen(line) - 4);
	fd = open(texture->so, O_RDONLY | O_WRONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nNo such file or directory: ", 2);
		ft_putstr_fd(texture->so, 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	close (fd);
	if (check_sixty_four(texture->so) == 1)
		return (error_message("Texture SO does not have 64*64 format"));
	return (0);
}

int	texture_we(char *line, t_texture *texture)
{
	int	fd;

	if (ft_strlen(line) <= 4)
		return (error_message("Texture WE is too short"));
	if (check_extension(&line[3], ".xpm\n") == 1)
		return (1);
	if (texture->we != NULL)
		return (error_message("Texture WE have multiple definition"));
	texture->we = ft_substr(line, 3, ft_strlen(line) - 4);
	fd = open(texture->we, O_RDONLY | O_WRONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nNo such file or directory: ", 2);
		ft_putstr_fd(texture->we, 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	close (fd);
	if (check_sixty_four(texture->we) == 1)
		return (error_message("Texture WE does not have 64*64 format"));
	return (0);
}

int	texture_ea(char *line, t_texture *texture)
{
	int	fd;

	if (ft_strlen(line) <= 4)
		return (error_message("Texture EA is too short"));
	if (check_extension(&line[3], ".xpm\n") == 1)
		return (1);
	if (texture->ea != NULL)
		return (error_message("Texture EA have multiple definition"));
	texture->ea = ft_substr(line, 3, ft_strlen(line) - 4);
	fd = open(texture->ea, O_RDONLY | O_WRONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nNo such file or directory: ", 2);
		ft_putstr_fd(texture->ea, 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	close (fd);
	if (check_sixty_four(texture->ea) == 1)
		return (error_message("Texture EA does not have 64*64 format"));
	return (0);
}
