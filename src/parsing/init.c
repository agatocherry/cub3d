#include "../../include/cub3d.h"

void    set_rest(t_player *pl, char init_dir)
{
    if (init_dir == 'W')
    {
        pl->dir_x = 0;
        pl->dir_y = -1;
        pl->plane_x = -0.66;
        pl->plane_y = 0;
    }
    else
    {
        pl->dir_x = 0;
        pl->dir_y = 1;
        pl->plane_x = 0.66;
        pl->plane_y = 0;
    }
}

void    initial_dir(t_player *pl, char init_dir)
{
    if (init_dir == 'N')
    {
        pl->dir_x = -1;
        pl->dir_y = 0;
        pl->plane_x = 0;
        pl->plane_y = 0.66;
    }
    else if (init_dir == 'S')
    {
        pl->dir_x = 1;
        pl->dir_y = 0;
        pl->plane_x = -0.66;
        pl->plane_y = 0;
    }
    else
        set_rest(pl, init_dir);
}

int init_player(t_cub *cub)
{
    char init_dir;

    //loop that looks for N or S or W or E
    //Save : player->x and player->y
    //Get the player direction for function "initial-dir()"

    //Remove these 3 lines once parsing is done
    cub->player.x = 11.5;
    cub->player.y = 27;
    init_dir = 'N';
    //

    initial_dir(&cub->player, init_dir);
    cub->player.camera = 0;
    cub->player.left = 0;
    cub->player.right = 0;
    cub->player.rotleft = 0;
    cub->player.rotright = 0;
    cub->player.forward = 0;
    cub->player.backwards = 0;
    return (0);
}