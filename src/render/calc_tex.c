/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:04:58 by ofadahun          #+#    #+#             */
/*   Updated: 2023/10/12 12:06:23 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	calc_line_height(t_cub3D *game)
{
	game->rays->lineheight = (int)(game->mlx->height / \
	game->rays->perp_wall_dist);
	game->rays->drawstart = -game->rays->lineheight / 2 + game->mlx->height / 2;
	if (game->rays->drawstart < 0)
		game->rays->drawstart = 0;
	game->rays->drawend = game->rays->lineheight / 2 + game->mlx->height / 2;
	if (game->rays->drawend >= game->mlx->height)
		game->rays->drawend = game->mlx->height - 1;
}

void	calc_texture(t_cub3D *game)
{
	game->textures->tex = game->textures->texture[game->rays->side];
	game->textures->tex_x = roundf(game->rays->tilepos * \
	game->textures->tex->width);
	if (game->rays->side < 2)
		game->textures->tex_x = roundf((1 - game->rays->tilepos) * \
		game->textures->tex->width);
	if (game->textures->tex_x >= (int)game->textures->tex->width)
		game->textures->tex_x = (int)(game->textures->tex->width) - 1;
	game->textures->y_inc = (float)game->textures->tex->height / \
	(game->rays->lineheight + 1);
	game->textures->y = (game->rays->drawstart - game->mlx->height / 2 + \
	game->rays->lineheight / 2) * game->textures->y_inc;
}

void	calc_tilepos(t_cub3D *game, double ray_dir_x, double ray_dir_y)
{
	if (game->rays->side % 2)
		game->rays->tilepos = fmod(game->ply->pos->y + \
		ray_dir_y * game->rays->perp_wall_dist, 1);
	else
		game->rays->tilepos = fmod(game->ply->pos->x + \
		ray_dir_x * game->rays->perp_wall_dist, 1);
}
