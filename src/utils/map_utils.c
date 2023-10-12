/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:58:39 by ofadahun          #+#    #+#             */
/*   Updated: 2023/10/07 10:21:02 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	draw_line(mlx_image_t *image, int width, int height, unsigned int color)
{
	int			i;

	i = 0;
	while (i < width)
	{
		mlx_put_pixel(image, i, height, color);
		i++;
	}
	return (0);
}

int	paint_colors(mlx_image_t *image, int width, int height, unsigned int color)
{
	int	i;

	i = 0;
	while (i < height)
	{
		draw_line(image, width, i, color);
		i++;
	}
	return (0);
}

char	*make_vs(int max_row)
{
	int		i;
	char	*vs;

	i = 0;
	vs = malloc(max_row + 1);
	if (!vs)
		return (NULL);
	while (i < max_row)
	{
		vs[i] = 'V';
		i++;
	}
	vs[i] = '\0';
	return (vs);
}

void	make_raw_map_copy(t_cub3D *game)
{
	int		max_row;
	t_list	*new;

	max_row = find_max_row(game->map_headref_copy);
	new = ft_lstnew(make_vs(max_row));
	ft_lstadd_front(&game->map_headref_copy, new);
	ft_lstadd_back(&game->map_headref_copy, ft_lstnew(make_vs(max_row)));
	game->copy_map = convert_linked_list_to_array(&game->map_headref_copy);
}
