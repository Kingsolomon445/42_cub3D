/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:09:40 by ofadahun          #+#    #+#             */
/*   Updated: 2023/10/12 12:06:57 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	read_textures(t_cub3D *game, char *line)
{
	if (starts_with(line, "NO") && !game->wall_textures[0])
		game->wall_textures[0] = ft_strtrim(line, "NO ");
	else if (starts_with(line, "EA") && !game->wall_textures[1])
		game->wall_textures[1] = ft_strtrim(line, "EA ");
	else if (starts_with(line, "SO") && !game->wall_textures[2])
		game->wall_textures[2] = ft_strtrim(line, "SO ");
	else if (starts_with(line, "WE") && !game->wall_textures[3])
		game->wall_textures[3] = ft_strtrim(line, "WE ");
	else if (starts_with(line, "F") && !game->floor_color)
		game->floor_color = ft_strdup(line);
	else if (starts_with(line, "C") && !game->ceiling_color)
		game->ceiling_color = ft_strdup(line);
	else
		return (0);
	return (1);
}

static int	add_to_map(t_cub3D *game, char *line, char *copy_line)
{
	t_list	*new;

	if (!line || !copy_line)
		return (ft_free(line), ft_free(copy_line), 0);
	if (is_data_ambigious(line))
		return (printf("Data is ambiguous\n"), \
		ft_free(line), ft_free(copy_line), 0);
	new = ft_lstnew(line);
	if (!new)
		return (ft_free(line), ft_free(copy_line), 0);
	ft_lstadd_back(&game->map_headref, new);
	new = ft_lstnew(copy_line);
	if (!new)
		return (ft_free(copy_line), 0);
	ft_lstadd_back(&game->map_headref_copy, new);
	return (1);
}

static void	free_args(t_read_map *args)
{
	ft_free(args->copy_line);
	ft_free(args->line);
	ft_free(args->checker);
}

static void	init_trim_args(t_read_map *args)
{
	args->line = ft_strtrim(args->temp, "\n");
	args->copy_line = ft_strtrim(args->temp, "\n");
	args->checker = ft_strtrim(args->temp, " \v\t\b\f\n");
	ft_free(args->temp);
}

int	read_map(t_cub3D *game, t_read_map *args, int fd)
{
	args->empty = 0;
	args->temp = get_next_line(fd);
	while (args->temp)
	{
		init_trim_args(args);
		if (!args->line || !args->copy_line || !args->checker)
			return (free_args(args), ft_free(args), 0);
		else if (*args->checker || (!*args->checker && game->map_headref))
		{
			if (!*args->checker)
				args->empty = 1;
			else if (args->empty)
				return (free_args(args), ft_free(args), \
				printf("Map has empty lines\n"), 0);
			else if (!read_textures(game, args->checker))
			{
				if (!add_to_map(game, ft_strdup(args->line), \
				ft_strdup(args->copy_line)))
					return (free_args(args), ft_free(args), 0);
			}
		}
		free_args(args);
		args->temp = get_next_line(fd);
	}
	return (ft_free(args), 1);
}
