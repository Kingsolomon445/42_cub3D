/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:46:44 by ofadahun          #+#    #+#             */
/*   Updated: 2023/10/02 11:23:49 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_floor(t_cub3D *game)
{
	game->flr->vec->y = game->mlx->height / 2;
	game->flr->l_ray_x = game->ply->dir->x - game->ply->cam_plane->x;
	game->flr->l_ray_y = game->ply->dir->y - game->ply->cam_plane->y;
	game->flr->r_ray_x = game->ply->dir->x + game->ply->cam_plane->x;
	game->flr->r_ray_y = game->ply->dir->y + game->ply->cam_plane->y;
	game->flr->posz = 0.5 * game->mlx->height;
}

static void	update_floor_y(t_cub3D *game)
{
	game->flr->vec->x = 0;
	game->flr->curr_line = game->flr->vec->y - game->mlx->height / 2;
	game->flr->row_dist = game->flr->posz / game->flr->curr_line;
	game->flr->step_x = game->flr->row_dist * \
	(game->flr->r_ray_x - game->flr->l_ray_x) / game->mlx->width;
	game->flr->step_y = game->flr->row_dist * \
	(game->flr->r_ray_y - game->flr->l_ray_y) / game->mlx->width;
	game->flr->floor_x = game->ply->pos->x + game->flr->row_dist * \
	game->flr->l_ray_x;
	game->flr->floor_y = game->ply->pos->y + game->flr->row_dist * \
	game->flr->l_ray_y;
}

static void	display_floor_ceiling(t_cub3D *game)
{
	mlx_put_pixel(game->full_img, game->flr->vec->x, game->flr->vec->y, \
	game->textures->floor);
	mlx_put_pixel(game->full_img, game->flr->vec->x, game->mlx->height - \
	game->flr->vec->y - 1, game->textures->ceiling);
}

void	render_floor(t_cub3D *game)
{
	init_floor(game);
	while (game->flr->vec->y < game->mlx->height)
	{
		update_floor_y(game);
		while (game->flr->vec->x < game->mlx->width)
		{
			game->flr->floor_x += game->flr->step_x;
			game->flr->floor_y += game->flr->step_y;
			display_floor_ceiling(game);
			game->flr->vec->x++;
		}
		game->flr->vec->y++;
	}
}
