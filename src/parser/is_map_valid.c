/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:11:48 by ofadahun          #+#    #+#             */
/*   Updated: 2023/10/07 16:00:22 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	has_invalid_chars(t_list *headref)
{
	t_list	*current;
	char	*line;
	int		i;

	current = headref;
	while (current)
	{
		i = 0;
		line = (char *)current->content;
		while (line[i])
		{
			if (!ft_strchr("10NSEW \t\v\f\r", line[i]))
				return (1);
			i++;
		}
		current = current->next;
	}
	return (0);
}

static int	has_empty_line(t_list *headref)
{
	t_list	*current;

	current = headref;
	while (current)
	{
		if (!(*(char *)current->content))
			return (1);
		current = current->next;
	}
	return (0);
}

void	is_map_valid(t_cub3D *game)
{
	t_list	*headref;
	int		res;

	headref = game->map_headref;
	if (!headref)
		ft_error(game, "Sorry! Couldn't find the map.\n");
	else if (has_invalid_chars(headref))
		ft_error(game, "Map has invalid characters!\n");
	else if (has_empty_line(headref))
		ft_error(game, "Map has empty lines!\n");
	else if (count_occurences(headref, 'N') + count_occurences(headref, 'S') + \
	count_occurences(headref, 'E') + count_occurences(headref, 'W') != 1)
		ft_error(game, "Missing player starting position or too many!\n");
	else if (!is_surrounded_by_wall(headref))
		ft_error(game, "Map is not surrounded by wall!\n");
	append_char_to_lst(game);
	res = has_valid_path(game);
	if (res == 0)
		ft_error(game, "Map has unclosed walls\n");
	else if (res == -1)
		ft_error(game, "Malloc Error\n");
}
