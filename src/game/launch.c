/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:43:21 by agcolas           #+#    #+#             */
/*   Updated: 2022/06/27 15:36:11 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	close_game(t_cub *cub)
{
	parsing_garbage(cub);
	exit(EXIT_SUCCESS);
}

int	loop_game(t_cub *cub)
{
	cub->img.img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bpp,
			&cub->img.line_l, &cub->img.endian);
	draw_window(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img, 0, 0);
	mlx_destroy_image(cub->mlx, cub->img.img);
	return (0);
}

int	key_pressed(int key, t_cub *cub)
{
	if (key == 97)
		cub->player.left = 1;
	if (key == 100)
		cub->player.right = 1;
	if (key == 119)
		cub->player.forward = 1;
	if (key == 115)
		cub->player.backwards = 1;
	if (key == 65361)
		cub->player.rotleft = 1;
	if (key == 65363)
		cub->player.rotright = 1;
	if (key == 109 && cub->show_map == 0)
		cub->show_map = 1;
	else if (key == 109)
		cub->show_map = 0;
	if (key == 65307)
		close_game(cub);
	return (0);
}

int	key_released(int key, t_cub *cub)
{
	if (key == 97)
		cub->player.left = 0;
	if (key == 100)
		cub->player.right = 0;
	if (key == 119)
		cub->player.forward = 0;
	if (key == 115)
		cub->player.backwards = 0;
	if (key == 65361)
		cub->player.rotleft = 0;
	if (key == 65363)
		cub->player.rotright = 0;
	return (0);
}

int	game_launch(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
	{
		error_message("Error\nMlx_Init() failed");
		return (1);
	}
	cub->mlx_win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "Cub3d");
	if (!cub->mlx_win)
	{
		error_message("Error\nMlx_New_Window() failed");
		return (1);
	}
	parse_textures(cub);
	cub->win_up = 1;
	mlx_hook(cub->mlx_win, 2, 1L << 0, key_pressed, (void *)cub);
	mlx_key_hook(cub->mlx_win, key_released, (void *)cub);
	mlx_hook(cub->mlx_win, 17, 1, close_game, (void *)cub);
	mlx_loop_hook(cub->mlx, loop_game, (void *)cub);
	mlx_loop(cub->mlx);
	return (0);
}
