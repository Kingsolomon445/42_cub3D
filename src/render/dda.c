/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:14:46 by sbhatta           #+#    #+#             */
/*   Updated: 2023/10/07 10:15:15 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	check_hit(t_cub3D *game, int *hit)
{
	if (game->rays->map_x >= ft_lstsize(game->map_headref) || \
	game->rays->map_y >= (int)ft_strlen(game->map[game->rays->map_x]) || \
	game->map[game->rays->map_x][game->rays->map_y] == '1')
		*hit = 1;
}

void	perform_dda(t_cub3D *game, double delta_dx, double delta_dy)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (game->rays->side_dist_x < game->rays->side_dist_y)
		{
			game->rays->side_dist_x += delta_dx;
			game->rays->map_x += game->rays->step_x;
			game->rays->side = 3;
			if (game->rays->step_x < 0)
				game->rays->side = 1;
		}
		else
		{
			game->rays->side_dist_y += delta_dy;
			game->rays->map_y += game->rays->step_y;
			game->rays->side = 0;
			if (game->rays->step_y < 0)
				game->rays->side = 2;
		}
		check_hit(game, &hit);
	}
}
