#include "../../include/cub3d.h"

int parse_textures(t_cub *cub, t_file *file)
{
    file->texture.tex_imgEA = mlx_xpm_file_to_image(cub->mlx,
        file->texture.ea, &(file->texture.eaW), &(file->texture.eaH));
    file->texture.tex_imgNO = mlx_xpm_file_to_image(cub->mlx,
        file->texture.no, &(file->texture.noW), &(file->texture.noH));
    file->texture.tex_imgSO = mlx_xpm_file_to_image(cub->mlx,
        file->texture.so, &(file->texture.soW), &(file->texture.soH));
    file->texture.tex_imgWE = mlx_xpm_file_to_image(cub->mlx,
        file->texture.we, &(file->texture.weW), &(file->texture.weH));
    file->texture.texEA = (int *)mlx_get_data_addr(file->texture.tex_imgEA,
    &(file->texture.ea_bpp), &(file->texture.ea_sl), &(file->texture.ea_en));
    file->texture.texNO = (int *)mlx_get_data_addr(file->texture.tex_imgNO,
    &(file->texture.no_bpp), &(file->texture.no_sl), &(file->texture.no_en));
    file->texture.texSO = (int *)mlx_get_data_addr(file->texture.tex_imgSO,
    &(file->texture.so_bpp), &(file->texture.so_sl), &(file->texture.so_en));
    file->texture.texWE = (int *)mlx_get_data_addr(file->texture.tex_imgWE,
    &(file->texture.we_bpp), &(file->texture.we_sl), &(file->texture.we_en));
    return (1);
}