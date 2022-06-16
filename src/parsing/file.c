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

// static int	save(char *line, t_file *file, int nb_line)
// {
// 	if (ft_strncmp(line, "F", 1) == 0)
// 		color_f(line, &file->color);
// 	if (ft_strncmp(line, "C", 1) == 0)
// 		color_c(line, &file->color);
// 	if (ft_strncmp(line, "NO", 2) == 0)
// 		texture_no(line, &file->texture);
// 	if (ft_strncmp(line, "SO", 2) == 0)
// 		texture_so(line, &file->texture);
// 	if (ft_strncmp(line, "WE", 2) == 0)
// 		texture_we(line, &file->texture);
// 	if (ft_strncmp(line, "EA", 2) == 0)
// 		texture_ea(line, &file->texture);
// 	if (nb_line >= 1)
// 		nb_line++;
// 	if (is_map(line) == 0)
// 	{
// 		if (nb_line <= mapsize(file->map) + 1)
// 			map(line, file);
// 		if (nb_line == 0)
// 			nb_line++;
// 	}
// 	return (nb_line);
// }

int	error_infos(t_cub *cub)
{
	int	error;

	error = 0;
	if (!cub->tex.no || !cub->tex.so
		|| !cub->tex.we || !cub->tex.ea)
		error = 1;
	if (!cub->color.set)
	{
		if (error == 0)
			return (error_message("Miss color info"));
		else
			return (error_message("Miss texture and color info"));
	}
	if (error == 1)
		return (error_message("Miss texture info"));
	
	// if (mapsize(file->map) == 0)
	// 	return (error_message("Miss map info"));
	
	return (0);
}

int	parsing(char *file_name, t_cub *cub)
{
	int		fd;
	char	*line;
	int		nb_line;

	nb_line = 0;
	if (error_file(file_name) == 1)
		return (1);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (error_message(strerror(errno)));
	
	
	// while (ft_gnl(fd, &line) > 0)
	// {
	// 	nb_line = save(line, file, nb_line);
	// 	free(line);
	// }
	
	// Instead of saving in t_map, save in char **map
	// Make a fonction that counts the number of lines to malloc and the number of characters in the longest line
	// Make a fonction that adds enough spaces at the end of each to match the number of characters in the longest line
	// Save the colors in int format with function char_to_rgb()

	// Remove these lines once parsing is done
	cub->map = (char **)malloc(sizeof(char *) * 14);
	cub->map[0] = ft_strdup("111111111111111111111111111111111");
	cub->map[1] = ft_strdup("100000000011000000000000111111111");
	cub->map[2] = ft_strdup("101100000111000000000000111111111");
	cub->map[3] = ft_strdup("100100000000000000000000111111111");
	cub->map[4] = ft_strdup("111111111011000001110000000000001");
	cub->map[5] = ft_strdup("100000000011000001110111110111111");
	cub->map[6] = ft_strdup("111101111111110111000000100011111");
	cub->map[7] = ft_strdup("111101111111110111010100100011111");
	cub->map[8] = ft_strdup("110000001101010111000000100011111");
	cub->map[9] = ft_strdup("100000000000000011000000100011111");
	cub->map[10] = ft_strdup("100000000000000011010100100011111");
	cub->map[11] = ft_strdup("11000001110101011111011110N011111");
	cub->map[12] = ft_strdup("111101110111010101011110100011111");
	cub->map[13] = ft_strdup("111111110111111101111111111111111");

	cub->color.f = char_to_rgb("255, 0, 0"); // red
	cub->color.c = char_to_rgb("0, 255, 0"); // green
	cub->color.set = 1; // if no color info found, set = 0

	cub->tex.ea = ft_strdup("./assets/wood1.xpm");
	cub->tex.so = ft_strdup("./assets/wood3.xpm");
	cub->tex.no = ft_strdup("./assets/wood5.xpm");
	cub->tex.we = ft_strdup("./assets/wood4.xpm");
	//

	close(fd);
	// if (error_infos(file) == 1)
	// 	return (1);
	// if (error_map(file->map) == 1)
	// 	return (1);
	return (0);
}
