/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_data_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:39:22 by ofadahun          #+#    #+#             */
/*   Updated: 2023/10/07 15:32:16 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	has_wrong_texture_ext(t_cub3D *game)
{
	char	*ext;
	int		i;

	ext = ".png";
	i = 0;
	while (i < 4)
	{
		if (!ends_with(game->wall_textures[i], ext))
			return (1);
		i++;
	}
	return (0);
}

static int	has_wrong_texture_path(t_cub3D *game)
{
	int	fd;
	int	i;

	i = 0;
	while (i < 4)
	{
		fd = open(game->wall_textures[i], O_RDONLY);
		if (fd < 0)
			return (1);
		close(fd);
		i++;
	}
	return (0);
}

static int	is_data_complete(t_cub3D *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!game->wall_textures[i])
			return (0);
		i++;
	}
	return (1);
}

void	is_data_valid(t_cub3D *game)
{
	if (!is_data_complete(game))
		ft_error(game, "Incomplete data given\n");
	else if (has_wrong_rgb(game))
		ft_error(game, "Map has wrong rgb value or values\n");
	else if (has_wrong_texture_ext(game))
		ft_error(game, "Map has a wrong texture extension\n");
	else if (has_wrong_texture_path(game))
		ft_error(game, "Map has a wrong texture path\n");
}

int	is_data_ambigious(char *line)
{
	if (starts_with(line, "NO") || starts_with(line, "SO") || \
	starts_with(line, "WE") || starts_with(line, "EA") || \
	starts_with(line, "F") || starts_with(line, "C"))
		return (1);
	return (0);
}
