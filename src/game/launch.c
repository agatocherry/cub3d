/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:43:21 by agcolas           #+#    #+#             */
/*   Updated: 2022/06/08 13:10:56 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	close_game(t_cub *cub)
{
	parsing_garbage(&cub->file);
	exit(EXIT_SUCCESS);
}

int	loop_game(t_cub *cub)
{
	cub->img.img = mlx_new_image(cub->mlx, 640, 480);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bpp,
		&cub->img.line_l, &cub->img.endian);
	draw_window(&cub->player, &cub->img, &cub->ray);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img, 0, 0);
	mlx_destroy_image(cub->mlx, cub->img.img);
	return (0);
}

int	key_pressed(int key, t_cub *cub)
{
	// Add moveleft(), moveright(), moveup(), movedown(), rotateup(), rotatedown()
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
	if (key == 65307)
		close_game(cub);
	// printf("key: %d", key);
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
	cub->mlx_win = mlx_new_window(cub->mlx, 640, 480, "Cub3d");
	mlx_hook(cub->mlx_win, 2, 1L << 0, key_pressed, (void *)cub);
	mlx_key_hook(cub->mlx_win, key_released, (void *)cub);
	mlx_hook(cub->mlx_win, 17, 1, close_game, (void *)cub);
	mlx_loop_hook(cub->mlx, loop_game, (void *)cub);
	mlx_loop(cub->mlx);
	return (0);
}
