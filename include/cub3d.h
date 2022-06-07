/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:17:28 by agcolas           #+#    #+#             */
/*   Updated: 2022/06/07 11:47:08 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../libmlx/mlx.h"

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_texture;

typedef struct s_color
{
	char	*f;
	char	*c;
}	t_color;

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}	t_map;

typedef struct s_file
{
	t_color		color;
	t_texture	texture;
	t_map		*map;
}	t_file;

int		error_message(char *str);
int		error_file(char *file);
int		error_map(t_map *map);
int		parsing(char *file_name, t_file *file);
void	color_f(char *line, t_color *color);
void	color_c(char *line, t_color *color);
void	texture_no(char *line, t_texture *texture);
void	texture_so(char *line, t_texture *texture);
void	texture_we(char *line, t_texture *texture);
void	texture_ea(char *line, t_texture *texture);
int		mapsize(t_map *map);
t_map	*mapnew(char *line);
t_map	*maplast(t_map *map);
void	mapadd_back(t_map **amap, t_map *lnew);
void	mapclear(t_map **map);
int		is_map(char *line);
void	print_map(t_map *map);
void	map(char *line, t_file *file);
void	parsing_garbage(t_file *file);

int		game_launch(t_file *file);

#endif