/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:58:13 by sbhatta           #+#    #+#             */
/*   Updated: 2023/10/12 12:07:09 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_game_ptrs(t_cub3D *game)
{
	game->map_headref = NULL;
	game->map_headref_copy = NULL;
	game->floor_color = NULL;
	game->ceiling_color = NULL;
	game->floor_rgb = malloc(sizeof(t_rgb));
	game->ceiling_rgb = malloc(sizeof(t_rgb));
	game->textures = malloc(sizeof(t_textures));
	ft_memset(game->textures->texture, 0, sizeof(game->textures->texture));
	ft_memset(game->wall_textures, 0, sizeof(game->wall_textures));
	game->flr = malloc(sizeof(t_floor));
	game->flr->vec = malloc(sizeof(t_vec));
	game->flr->cell = malloc(sizeof(t_vec));
	game->flr->tex = malloc(sizeof(t_vec));
	game->rays = malloc(sizeof(t_raycast));
	game->ply = malloc(sizeof(t_player));
	game->ply->cam_plane = malloc(sizeof(t_double_vec));
	game->ply->pos = malloc(sizeof(t_double_vec));
	game->ply->dir = malloc(sizeof(t_double_vec));
	game->map = NULL;
	game->copy_map = NULL;
}

int	is_alloc_sucess(t_cub3D *game)
{
	if (!game->floor_rgb || !game->ceiling_rgb || \
	!game->textures || !game->flr || !game->rays \
	|| !game->ply)
		return (0);
	return (1);
}

void	init_cub3d(t_cub3D *game)
{
	make_raw_map_copy(game);
	is_data_valid(game);
	is_map_valid(game);
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!game->mlx)
		ft_error(game, "mlx initialization failed\n");
	game->full_img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	mlx_get_monitor_size(0, &game->width, &game->height);
	game->max_width = find_max_row(game->map_headref);
	game->player = mlx_new_image(game->mlx, 30, 30);
	mlx_image_to_window(game->mlx, game->full_img, 0, 0);
	set_ups(game),
	init_player_dir(game);
	mlx_loop_hook(game->mlx, main_loop, game);
	mlx_loop_hook(game->mlx, ft_key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	ft_free_game(game);
}

void	ft_leaks(void)
{
	system("leaks cub3D");
}

int	main(int argc, char *argv[])
{
	t_cub3D		*game;
	t_read_map	*args;
	char		*path;
	int			fd;

	if (argc < 2)
		return (printf("Too few arguments\n"), EXIT_FAILURE);
	game = malloc(sizeof(t_cub3D));
	if (!game)
		return (EXIT_FAILURE);
	init_game_ptrs(game);
	if (!is_alloc_sucess(game))
		ft_error(game, "Mallo Error\n");
	path = argv[1];
	if (!ends_with(path, ".cub"))
		ft_error(game, "Map has wrong extension\n");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error(game, "Error opening file\n");
	args = malloc(sizeof(t_read_map));
	if (!args)
		ft_error(game, "Malloc Error\n");
	if (!read_map(game, args, fd))
		ft_error(game, "Error reading Map\n");
	return (close(fd), init_cub3d(game), 0);
}
