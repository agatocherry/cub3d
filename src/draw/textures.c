/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shdorlin <shdorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:00:29 by shdorlin          #+#    #+#             */
/*   Updated: 2022/06/18 15:01:37 by shdorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	parse_textures(t_cub *cub)
{
	cub->tex.tex_img_ea = mlx_xpm_file_to_image(cub->mlx,
			cub->tex.ea, &(cub->tex.tex_w), &(cub->tex.tex_h));
	cub->tex.tex_img_no = mlx_xpm_file_to_image(cub->mlx,
			cub->tex.no, &(cub->tex.tex_w), &(cub->tex.tex_h));
	cub->tex.tex_img_so = mlx_xpm_file_to_image(cub->mlx,
			cub->tex.so, &(cub->tex.tex_w), &(cub->tex.tex_h));
	cub->tex.tex_img_we = mlx_xpm_file_to_image(cub->mlx,
			cub->tex.we, &(cub->tex.tex_w), &(cub->tex.tex_h));
	cub->tex.tex_ea = (int *)mlx_get_data_addr(cub->tex.tex_img_ea,
			&(cub->tex.tex_bpp), &(cub->tex.tex_sl), &(cub->tex.tex_en));
	cub->tex.tex_no = (int *)mlx_get_data_addr(cub->tex.tex_img_no,
			&(cub->tex.tex_bpp), &(cub->tex.tex_sl), &(cub->tex.tex_en));
	cub->tex.tex_so = (int *)mlx_get_data_addr(cub->tex.tex_img_so,
			&(cub->tex.tex_bpp), &(cub->tex.tex_sl), &(cub->tex.tex_en));
	cub->tex.tex_we = (int *)mlx_get_data_addr(cub->tex.tex_img_we,
			&(cub->tex.tex_bpp), &(cub->tex.tex_sl), &(cub->tex.tex_en));
	return (1);
}
