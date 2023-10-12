/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ups.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:16:36 by ofadahun          #+#    #+#             */
/*   Updated: 2023/10/07 17:42:16 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	find_player(t_cub3D *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (ft_strchr("NSWE", game->map[i][j]))
			{
				game->side_facing = game->map[i][j];
				game->ply->pos->x = i + 0.5;
				game->ply->pos->y = j + 0.5;
			}
			j++;
		}
		i++;
	}
}

void	set_up_textures(t_cub3D *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->textures->texture[i] = mlx_load_png(game->wall_textures[i]);
		i++;
	}
	game->textures->floor = create_color(game->floor_rgb->r, \
	game->floor_rgb->g, game->floor_rgb->b);
	game->textures->ceiling = create_color(game->ceiling_rgb->r, \
	game->ceiling_rgb->g, game->ceiling_rgb->b);
}

void	set_ups(t_cub3D *game)
{
	set_up_textures(game);
	game->map = convert_linked_list_to_array(&game->map_headref);
	find_player(game);
}
