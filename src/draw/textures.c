#include "../../include/cub3d.h"

int parse_textures(t_cub *cub)
{
    cub->tex.tex_imgEA = mlx_xpm_file_to_image(cub->mlx,
        cub->tex.ea, &(cub->tex.tex_W), &(cub->tex.tex_H));
    cub->tex.tex_imgNO = mlx_xpm_file_to_image(cub->mlx,
        cub->tex.no, &(cub->tex.tex_W), &(cub->tex.tex_H));
    cub->tex.tex_imgSO = mlx_xpm_file_to_image(cub->mlx,
        cub->tex.so, &(cub->tex.tex_W), &(cub->tex.tex_H));
    cub->tex.tex_imgWE = mlx_xpm_file_to_image(cub->mlx,
        cub->tex.we, &(cub->tex.tex_W), &(cub->tex.tex_H));
    cub->tex.texEA = (int *)mlx_get_data_addr(cub->tex.tex_imgEA,
    &(cub->tex.tex_bpp), &(cub->tex.tex_sl), &(cub->tex.tex_en));
    cub->tex.texNO = (int *)mlx_get_data_addr(cub->tex.tex_imgNO,
    &(cub->tex.tex_bpp), &(cub->tex.tex_sl), &(cub->tex.tex_en));
    cub->tex.texSO = (int *)mlx_get_data_addr(cub->tex.tex_imgSO,
    &(cub->tex.tex_bpp), &(cub->tex.tex_sl), &(cub->tex.tex_en));
    cub->tex.texWE = (int *)mlx_get_data_addr(cub->tex.tex_imgWE,
    &(cub->tex.tex_bpp), &(cub->tex.tex_sl), &(cub->tex.tex_en));
    return (1);
}