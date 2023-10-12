/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:59:06 by ofadahun          #+#    #+#             */
/*   Updated: 2023/10/07 10:16:55 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

uint32_t	create_color(int red, int green, int blue)
{
	return (((red & 0xff) << 24) + ((green & 0xff) << 16) + \
	((blue & 0xff) << 8) + (255 & 0xFF));
}

uint32_t	convert_to_rgba(uint8_t *pixels)
{
	uint32_t	color;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;

	r = *pixels;
	g = *(pixels + 1);
	b = *(pixels + 2);
	a = *(pixels + 3);
	color = ((uint32_t)r << 24) | ((uint32_t)g << 16) | \
	((uint32_t)b << 8) | (uint32_t)a;
	return (color);
}

void	verline(t_cub3D *game, int x)
{
	long long	tex_pixel;
	int			y;
	int			y2;

	y = game->rays->drawstart;
	y2 = game->rays->drawend;
	while (y <= y2)
	{
		tex_pixel = (int)(game->textures->y) * game->textures->tex->width + \
		game->textures->tex_x;
		mlx_put_pixel(game->full_img, x, y, \
		convert_to_rgba(&(game->textures->tex->pixels[tex_pixel * 4])));
		game->textures->y += game->textures->y_inc;
		y++;
	}
}
