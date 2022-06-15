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
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720
# define TEXWIDTH 64
# define TEXHEIGHT 64

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	void	*tex_imgNO;
	void	*tex_imgSO;
	void	*tex_imgWE;
	void	*tex_imgEA;
	int		eaW;
	int		eaH;
	int		noW;
	int		noH;
	int		weW;
	int		weH;
	int		soW;
	int		soH;
	int		ea_bpp;
	int		ea_sl;
	int		ea_en;
	int		no_bpp;
	int		no_sl;
	int		no_en;
	int		so_bpp;
	int		so_sl;
	int		so_en;
	int		we_bpp;
	int		we_sl;
	int		we_en;
	int	*texNO;
	int	*texSO;
	int	*texWE;
	int		*texEA;
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

typedef struct s_player
{
	char	init_dir;
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	camera;
	double	plane_x;
	double	plane_y;
	int		left;
	int		right;
	int		forward;
	int		backwards;
	int		rotleft;
	int		rotright;
}	t_player;

typedef struct s_ray
{
	int		mapX;
	int		mapY;
	double	dir_x;
	double	dir_y;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	double	wallX;
	char	wallDir;
}	t_ray;

typedef struct s_file
{
	t_color		color;
	t_texture	texture;
	t_map		*map;
}	t_file;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
}	t_data;

typedef struct s_cub
{
	t_file		file;
	t_player	player;
	t_ray		ray;
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_texture	texture;
	t_color		colors;
	char		**map;
}	t_cub;

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

int		game_launch(t_cub *cub);
void    draw_window(t_texture *tex, t_player *pl, t_data *img, t_ray *ray);
void	moveleft(t_player *pl);
void    rotateright(t_player *pl);
void    rotateleft(t_player *pl);
void    movebackward(t_player *pl);
void    moveforward(t_player *pl);
void    moveright(t_player *pl);
int		parse_textures(t_cub *cub, t_file *file);
int		init_player(t_cub *cub);

extern int worldMap[24][24];

#endif
