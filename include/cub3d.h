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
	int		tex_W;
	int		tex_H;
	int		tex_bpp;
	int		tex_sl;
	int		tex_en;
	int		*texNO;
	int		*texSO;
	int		*texWE;
	int		*texEA;
}	t_texture;

typedef struct s_color
{
	int	set;
	int	f;
	int	c;
}	t_color;

typedef struct s_player
{
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
	int		*text;
}	t_ray;

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
	t_player	player;
	t_ray		ray;
	t_data		img;
	t_data		minimap;
	t_texture	tex;
	t_color		color;
	void		*mlx;
	void		*mlx_win;
	char		**map;
	int			show_map;
}	t_cub;

int		error_message(char *str);
int		error_file(char *file);
//int		error_map(t_map *map);
int		parsing(char *file_name, t_cub *cub);
void	color_f(char *line, t_color *color);
void	color_c(char *line, t_color *color);
void	texture_no(char *line, t_texture *texture);
void	texture_so(char *line, t_texture *texture);
void	texture_we(char *line, t_texture *texture);
void	texture_ea(char *line, t_texture *texture);
//int		mapsize(t_map *map);
//t_map	*mapnew(char *line);
//t_map	*maplast(t_map *map);
//void	mapadd_back(t_map **amap, t_map *lnew);
void	mapclear(char **map);
int		is_map(char *line);
void	print_map(char **map);
void	map(char *line, t_cub *cub);
void	parsing_garbage(t_cub *cub);

int		game_launch(t_cub *cub);
void    draw_window(t_cub *cub);
void	moveleft(char **map, t_player *pl);
void    rotateright(t_player *pl);
void    rotateleft(t_player *pl);
void    movebackward(char **map, t_player *pl);
void    moveforward(char **map, t_player *pl);
void    moveright(char **map, t_player *pl);
int		parse_textures(t_cub *cub);
int		init_player(t_cub *cub);
void    draw_ceiling(t_data *img, int stop, int col, t_color *c);
void    draw_floor(t_data *img, int begin, int col, t_color *c);
void    draw_texture(t_data *img, t_ray *r, int col, int texX);
void    draw_lines(int col, t_ray *r, t_data *img, t_color *c);
void    get_wallparams(t_ray *r, t_player *pl, t_texture *tex);
void    get_rayhit(t_ray *r, char **map);
void    get_raystep(t_ray *r, t_player *pl);
void    get_rayparams(t_ray *r, t_player *pl);

#endif
