/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:56:25 by ofadahun          #+#    #+#             */
/*   Updated: 2023/10/12 12:06:33 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	calc_perp_wall_dist(t_cub3D *game, double ray_dir_x, \
double ray_dir_y)
{
	if (game->rays->side % 2)
		game->rays->perp_wall_dist = (game->rays->map_x - game->ply->pos->x + \
		(1 - game->rays->step_x) / 2) / ray_dir_x;
	else
		game->rays->perp_wall_dist = (game->rays->map_y - game->ply->pos->y + \
		(1 - game->rays->step_y) / 2) / ray_dir_y;
}

static void	calc_side_dist(t_cub3D *game, double ray_dir_x, double ray_dir_y)
{
	if (ray_dir_x < 0)
	{
		game->rays->step_x = -1;
		game->rays->side_dist_x = \
		(game->ply->pos->x - game->rays->map_x) * game->rays->delta_dist_x;
	}
	else
	{
		game->rays->step_x = 1;
		game->rays->side_dist_x = (game->rays->map_x + 1 - game->ply->pos->x) \
		* game->rays->delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		game->rays->step_y = -1;
		game->rays->side_dist_y = (game->ply->pos->y - game->rays->map_y) \
		* game->rays->delta_dist_y;
	}
	else
	{
		game->rays->step_y = 1;
		game->rays->side_dist_y = (game->rays->map_y + 1 - game->ply->pos->y) \
		* game->rays->delta_dist_y;
	}
}

static void	init_ray_calc(t_cub3D *game, int i, \
double *ray_dir_x, double *ray_dir_y)
{
	game->rays->camera_x = 2 * i / (double)game->mlx->width - 1;
	*ray_dir_x = game->ply->dir->x + \
	game->ply->cam_plane->x * game->rays->camera_x;
	*ray_dir_y = game->ply->dir->y + \
	game->ply->cam_plane->y * game->rays->camera_x;
	game->rays->map_x = (int)game->ply->pos->x;
	game->rays->map_y = (int)game->ply->pos->y;
	game->rays->side = 0;
	game->rays->delta_dist_x = (float)fabs(1 / *ray_dir_x);
	game->rays->delta_dist_y = (float)fabs(1 / *ray_dir_y);
	calc_side_dist(game, *ray_dir_x, *ray_dir_y);
	perform_dda(game, game->rays->delta_dist_x, game->rays->delta_dist_y);
	calc_perp_wall_dist(game, *ray_dir_x, *ray_dir_y);
}

void	ray_cast_loop(t_cub3D *game)
{
	int		i;
	double	ray_dir_x;
	double	ray_dir_y;

	i = 0;
	render_floor(game);
	while (i < game->mlx->width)
	{
		init_ray_calc(game, i, &ray_dir_x, &ray_dir_y);
		calc_tilepos(game, ray_dir_x, ray_dir_y);
		calc_line_height(game);
		calc_texture(game);
		verline(game, i);
		i++;
	}
}
