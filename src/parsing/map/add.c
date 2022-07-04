/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:33:21 by agcolas           #+#    #+#             */
/*   Updated: 2022/07/04 17:43:51 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static int	size_line(char *file_name)
{
	int		size;
	char	*line;
	int		fd;

	size = 0;
	fd = open(file_name, O_RDONLY);
	while (ft_gnl(fd, &line) > 0)
	{
		if (is_map(line, 0) == 0)
			break ;
		free(line);
	}
	if (line)
		free(line);
	while (ft_gnl(fd, &line) > 0)
	{
		free(line);
		size++;
	}
	close (fd);
	return (size);
}

static int	longest_strlen(char *file_name)
{
	int		size;
	char	*line;
	int		fd;

	size = 0;
	fd = open(file_name, O_RDONLY);
	while (ft_gnl(fd, &line) > 0)
	{
		if (is_map(line, 0) == 0)
			break ;
		free(line);
	}
	if (line)
		free(line);
	while (ft_gnl(fd, &line) > 0)
	{
		if (ft_strlen(line) > size)
			size = ft_strlen(line);
		free(line);
	}
	close (fd);
	return (size - 1);
}

static char	*ft_strlndup(const char *s, int size)
{
	char	*new_s;
	int		i;

	i = 0;
	new_s = malloc(sizeof(char) * (size) + 1);
	if (new_s == NULL)
		return (NULL);
	while (s[i] && s[i] != '\n' && i < size)
	{
		new_s[i] = s[i];
		i++;
	}
	if (i == 0)
	{
		free (new_s);
		return (NULL);
	}
	while (i < size)
	{
		new_s[i] = ' ';
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

static int	add_strings(int size_l, int fd, int longest_char, t_cub *cub)
{
	int		i;
	char	*tmp;

	i = 1;
	while (i < size_l && ft_gnl(fd, &tmp) > 0)
	{
		cub->map[i] = ft_strlndup(tmp, longest_char);
		if (cub->map[i] == NULL)
		{
			free(tmp);
			while (ft_gnl(fd, &tmp) > 0)
				free(tmp);
			return (error_message("Map have an empty line"));
		}
		i++;
		free(tmp);
	}
	while (ft_gnl(fd, &tmp) > 0)
		free(tmp);
	cub->map[i] = NULL;
	return (0);
}

int	add_map(int fd, char *file_name, t_cub *cub, char *line)
{
	int		longest_char;
	int		size_l;

	longest_char = longest_strlen(file_name);
	size_l = size_line(file_name) + 2;
	cub->map = malloc(sizeof(char *) * size_l);
	if (cub->map == NULL)
		return (error_message("Malloc failed"));
	cub->map[0] = ft_strlndup(line, longest_char);
	if (cub->map[0] == NULL)
		return (error_message("Malloc failed"));
	if (add_strings(size_l, fd, longest_char, cub) == 1)
		return (1);
	if (error_map(cub, longest_char) == 1)
		return (1);
	return (0);
}
