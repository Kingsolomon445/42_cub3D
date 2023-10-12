/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:13:05 by ofadahun          #+#    #+#             */
/*   Updated: 2023/10/07 15:45:59 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_player_pos(char **map, t_valid_path *arg)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NWES", map[i][j]))
			{
				arg->player_row = i;
				arg->player_col = j;
			}
			j++;
		}
		i++;
	}
}

static int	is_valid_move(int row, int col, int win_rows, char **map)
{
	if (row >= 0 && row < win_rows && col >= 0 && col < \
	(int)ft_strlen(map[row]) && map[row][col] != '1')
		return (1);
	return (0);
}

static void	flood_fill(int row, int col, t_valid_path *arg, char **map)
{
	if (!is_valid_move(row, col, arg->win_rows, map) || \
	(arg->visited)[row][col])
		return ;
	arg->visited[row][col] = 2;
	flood_fill(row - 1, col, arg, map);
	flood_fill(row + 1, col, arg, map);
	flood_fill(row, col - 1, arg, map);
	flood_fill(row, col + 1, arg, map);
}

int	**ft_make_int_array(int rows, int cols)
{
	int	**arr;
	int	*tab;
	int	i;
	int	j;

	arr = malloc(sizeof(int *) * rows);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		tab = malloc(sizeof(int) * cols);
		if (!tab)
			return (ft_free_int_array(arr, i), NULL);
		j = 0;
		while (j < cols)
			tab[j++] = 0;
		arr[i++] = tab;
	}
	return (arr);
}

int	has_valid_path(t_cub3D *game)
{
	int				i;
	int				j;
	t_valid_path	*arg;

	arg = malloc(sizeof(t_valid_path));
	if (!arg)
		return (-1);
	init_player_pos(game->copy_map, arg);
	arg->win_rows = ft_lstsize(game->map_headref_copy);
	arg->win_cols = find_max_row(game->map_headref_copy) + 2;
	arg->visited = ft_make_int_array(arg->win_rows, arg->win_cols);
	flood_fill(arg->player_row, arg->player_col, arg, game->copy_map);
	i = -1;
	while (++i < arg->win_rows)
	{
		j = -1;
		while (++j < (int)ft_strlen(game->copy_map[i]))
		{
			if (game->copy_map[i][j] == 'V' && arg->visited[i][j])
				return (ft_free_int_array(arg->visited, \
				arg->win_rows), ft_free(arg), 0);
		}
	}
	return (ft_free_int_array(arg->visited, arg->win_rows), ft_free(arg), 1);
}
