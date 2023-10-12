/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:00:10 by sbhatta           #+#    #+#             */
/*   Updated: 2023/10/06 13:05:41 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_move_valid(t_cub3D *game, int col, int row)
{
	if (col >= ft_lstsize(game->map_headref) || \
	row >= (int)ft_strlen(game->map[col]) || \
		game->map[col][row] == '1')
		return (0);
	return (1);
}

void	move_left_right(t_cub3D *game, int flag)
{
	int	i;
	int	j;

	i = (int)(game->ply->pos->x + (flag * game->ply->dir->y) * \
	game->rays->move_speed);
	j = (int)(game->ply->pos->y + (-flag * game->ply->dir->x) * \
	game->rays->move_speed);
	if (is_move_valid(game, i, (int)game->ply->pos->y))
		game->ply->pos->x += flag * game->ply->dir->y * game->rays->move_speed;
	if (is_move_valid(game, (int)game->ply->pos->x, j))
		game->ply->pos->y -= flag * game->ply->dir->x * game->rays->move_speed;
}

void	move_up_down(t_cub3D *game, int flag)
{
	int	i;
	int	j;

	i = (int)(game->ply->pos->x + (flag * game->ply->dir->x) * \
	game->rays->move_speed);
	j = (int)(game->ply->pos->y + (flag * game->ply->dir->y) * \
	game->rays->move_speed);
	if (is_move_valid(game, i, (int)game->ply->pos->y))
		game->ply->pos->x += flag * game->ply->dir->x * game->rays->move_speed;
	if (is_move_valid(game, (int)game->ply->pos->x, j))
		game->ply->pos->y += flag * game->ply->dir->y * game->rays->move_speed;
}

void	rotate_view(t_cub3D *game, int flag)
{
	double	old_dirx;
	double	old_planex;
	double	sine;
	double	cosine;

	old_dirx = game->ply->dir->x;
	old_planex = game->ply->cam_plane->x;
	sine = sin(flag * (game->rays->rot_speed / 2));
	cosine = cos(flag * (game->rays->rot_speed / 2));
	game->ply->dir->x = game->ply->dir->x * cosine - game->ply->dir->y * sine;
	game->ply->dir->y = old_dirx * sine + game->ply->dir->y * cosine;
	if (game->ply->dir->x > 1.0)
		game->ply->dir->x = 1.0;
	if (game->ply->dir->y < -1.0)
		game->ply->dir->y = -1.0;
	game->ply->cam_plane->x = game->ply->cam_plane->x * cosine \
	- game->ply->cam_plane->y * sine;
	game->ply->cam_plane->y = old_planex * \
	sine + game->ply->cam_plane->y * cosine;
}
