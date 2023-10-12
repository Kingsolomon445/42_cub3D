/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rgb_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:50:52 by ofadahun          #+#    #+#             */
/*   Updated: 2023/10/12 12:06:49 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	is_all_digits(char *value)
{
	int		i;

	i = 0;
	while (value[i])
	{
		if ((i == 0 && ft_strchr("+-", value[i])) || ft_isdigit(value[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

static int	is_within_range(t_cub3D *game, \
char *value, int type, int rgb_val_pos)
{
	int	int_value;

	int_value = ft_atoi(value);
	if (int_value < 0 || int_value > 255)
		return (0);
	if (type == CEILING)
	{
		if (rgb_val_pos == 0)
			game->ceiling_rgb->r = int_value;
		else if (rgb_val_pos == 1)
			game->ceiling_rgb->g = int_value;
		else if (rgb_val_pos == 2)
			game->ceiling_rgb->b = int_value;
	}
	if (type == FLOOR)
	{
		if (rgb_val_pos == 0)
			game->floor_rgb->r = int_value;
		else if (rgb_val_pos == 1)
			game->floor_rgb->g = int_value;
		else if (rgb_val_pos == 2)
			game->floor_rgb->b = int_value;
	}
	return (1);
}

static int	is_rgb_value_wrong(t_cub3D *game, char **rgbv_values, int type)
{
	int		i;
	char	*value;

	i = 0;
	while (rgbv_values[i])
	{
		value = ft_strtrim(rgbv_values[i], " \t\v\f\r\b");
		if (!value)
			return (-1);
		if (!is_all_digits(value))
			return (ft_free(value), 1);
		if (!is_within_range(game, value, type, i))
			return (ft_free(value), 1);
		ft_free(value);
		i++;
	}
	return (0);
}

int	has_wrong_rgb(t_cub3D *game)
{
	char	**floor_rgb_values;
	char	**ceiling_rgb_values;
	char	*ceiling;
	char	*floor;

	if (!game->ceiling_color || !game->floor_color)
		return (1);
	if (count_occ_in_str(game->ceiling_color, ',') != 2 || \
	count_occ_in_str(game->floor_color, ',') != 2)
		return (1);
	ceiling = ft_strtrim(game->ceiling_color + 1, " \t\v\f\r\b");
	floor = ft_strtrim(game->floor_color + 1, " \t\v\f\r\b");
	ceiling_rgb_values = ft_split(ceiling, ',');
	floor_rgb_values = ft_split(floor, ',');
	if (ft_count_str_array(ceiling_rgb_values) != 3 \
	|| ft_count_str_array(floor_rgb_values) != 3)
		return (ft_free(ceiling), ft_free(floor), \
		ft_free_split(ceiling_rgb_values), ft_free_split(floor_rgb_values), 1);
	if (is_rgb_value_wrong(game, ceiling_rgb_values, CEILING) \
	|| is_rgb_value_wrong(game, floor_rgb_values, FLOOR))
		return (ft_free(ceiling), ft_free(floor), \
		ft_free_split(ceiling_rgb_values), ft_free_split(floor_rgb_values), 1);
	return (ft_free(ceiling), ft_free(floor), \
	ft_free_split(ceiling_rgb_values), ft_free_split(floor_rgb_values), 0);
}
