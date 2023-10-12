/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:14:29 by ofadahun          #+#    #+#             */
/*   Updated: 2023/10/07 16:01:42 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_error(t_cub3D *game, char *error_str)
{
	printf("%s", error_str);
	ft_free_game(game);
	exit(EXIT_FAILURE);
}

void	ft_delete_texture(t_cub3D *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		ft_free(game->wall_textures[i]);
		if (game->textures->texture[i])
			mlx_delete_texture(game->textures->texture[i]);
		i++;
	}
}

void	ft_free_game(t_cub3D *game)
{
	ft_delete_texture(game);
	ft_free(game->ply->cam_plane);
	ft_free(game->textures);
	ft_free(game->ply->pos);
	ft_free(game->ply->dir);
	ft_free(game->ply);
	ft_free(game->rays);
	ft_free(game->flr->vec);
	ft_free(game->flr->cell);
	ft_free(game->flr->tex);
	ft_free(game->flr);
	ft_free(game->floor_color);
	ft_free(game->ceiling_color);
	ft_free(game->floor_rgb);
	ft_free(game->ceiling_rgb);
	ft_lstclear(&game->map_headref, ft_free);
	ft_lstclear(&game->map_headref_copy, ft_free);
	ft_free_split(game->map);
	ft_free_split(game->copy_map);
	ft_free(game);
}
