/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 09:22:42 by sbhatta           #+#    #+#             */
/*   Updated: 2023/10/07 10:21:11 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_east_west(t_cub3D *game, int dir_flag, int cam_flag)
{
	game->ply->dir->x = 0;
	game->ply->dir->y = 1 * dir_flag;
	game->ply->cam_plane->x = 0.66 * cam_flag;
	game->ply->cam_plane->y = 0;
}

static void	set_north_south(t_cub3D *game, int dir_flag, int cam_flag)
{
	game->ply->dir->x = 1 * dir_flag;
	game->ply->dir->y = 0;
	game->ply->cam_plane->x = 0;
	game->ply->cam_plane->y = 0.66 * cam_flag;
}

void	init_player_dir(t_cub3D *game)
{
	if (game->side_facing == 'W')
		set_east_west(game, -1, 1);
	else if (game->side_facing == 'E')
		set_east_west(game, 1, -1);
	else if (game->side_facing == 'N')
		set_north_south(game, -1, -1);
	else if (game->side_facing == 'S')
		set_north_south(game, 1, 1);
	game->rays->move_speed = 0.040;
	game->rays->rot_speed = 0.04;
}
