/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:53:10 by ofadahun          #+#    #+#             */
/*   Updated: 2023/10/07 09:20:20 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	mouse_rotate(t_cub3D *game)
{
	int		mouse_x;
	int		mouse_y;

	mlx_get_mouse_pos(game->mlx, &mouse_x, &mouse_y);
	if (mouse_x > game->mlx->width / 2)
		rotate_view(game, 1);
	if (mouse_x < game->mlx->width / 2)
		rotate_view(game, -1);
}

void	ft_key_hook(void *param)
{
	t_cub3D	*game;

	game = param;
	if (mlx_is_mouse_down(game->mlx, MLX_MOUSE_BUTTON_LEFT))
		mouse_rotate(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_view(game, -1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_view(game, 1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_up_down(game, 1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_up_down(game, -1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left_right(game, 1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_left_right(game, -1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
		ft_free_game(game);
		exit(EXIT_SUCCESS);
	}
}

void	main_loop(void *param)
{
	t_cub3D		*game;

	game = param;
	ray_cast_loop(game);
}
