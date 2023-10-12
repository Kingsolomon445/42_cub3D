/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:56:23 by sbhatta           #+#    #+#             */
/*   Updated: 2023/10/07 16:59:51 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/include/ft_printf.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# define WIDTH 1024
# define HEIGHT 512
# define CEILING 2
# define FLOOR 0
# define WALL 1

typedef struct s_textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
	mlx_texture_t	*texture[4];
	mlx_texture_t	*tex;
	uint32_t		floor;
	uint32_t		ceiling;
	int				tex_x;
	double			y;
	double			y_inc;
}	t_textures;

typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

typedef struct s_double_vec
{
	double	x;
	double	y;
}	t_double_vec;

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

typedef struct s_player
{
	t_double_vec	*pos;
	t_double_vec	*dir;
	t_double_vec	*cam_plane;
}	t_player;

typedef struct s_raycast
{
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			camera_x;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				side;
	double			move_speed;
	double			rot_speed;
	double			frame_time;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				tex_x;
	double			step;
	double			tilepos;
}	t_raycast;

typedef struct s_floor
{
	double	l_ray_x;
	double	l_ray_y;
	double	r_ray_x;
	double	r_ray_y;
	double	step_x;
	double	step_y;
	double	floor_x;
	double	floor_y;
	t_vec	*vec;
	t_vec	*cell;
	t_vec	*tex;
	uint8_t	*tex_pixel;
	float	posz;
	float	row_dist;
	int		curr_line;
}	t_floor;

typedef struct s_cub3D
{
	mlx_t			*mlx;
	mlx_image_t		*full_img;
	t_list			*map_headref;
	t_list			*map_headref_copy;
	char			*wall_textures[4];
	char			*floor_color;
	char			*ceiling_color;
	char			side_facing;
	int				width;
	int				height;
	mlx_image_t		*player;
	t_textures		*textures;
	t_rgb			*floor_rgb;
	t_rgb			*ceiling_rgb;
	int				max_width;
	t_raycast		*rays;
	char			**map;
	char			**copy_map;
	int				**visited;
	t_floor			*flr;
	t_player		*ply;
}	t_cub3D;

typedef struct s_valid_path
{
	int				player_row;
	int				player_col;
	int				win_rows;
	int				win_cols;
	int				**visited;
}	t_valid_path;

typedef struct s_read_map
{
	char	*line;
	char	*copy_line;
	char	*checker;
	char	*temp;
	int		empty;
}	t_read_map;

//INIT
void		init_player_dir(t_cub3D *game);

//HOOKS
void		ft_key_hook(void *param);
void		main_loop(void *param);

//PARSERS
int			read_map(t_cub3D *game, t_read_map *args, int fd);
void		print_map(t_list *headref);

//MAP CHECKS
char		*make_vs(int max_row);
void		make_raw_map_copy(t_cub3D *game);
void		is_map_valid(t_cub3D *game);
void		is_data_valid(t_cub3D *game);
int			is_data_ambigious(char *line);
int			has_wrong_rgb(t_cub3D *game);
int			is_surrounded_by_wall(t_list *headref);
int			has_valid_path(t_cub3D *game);

// MOVEMENTS
void		move_up_down(t_cub3D *game, int flag);
void		rotate_view(t_cub3D *game, int flag);
void		move_left_right(t_cub3D *game, int flag);

//UTILS
void		ft_error(t_cub3D *game, char *error_str);
void		ft_free_game(t_cub3D *game);

int			count_occurences(t_list *headref, char ch);

int			starts_with(char *whole, char *part);
int			ends_with(char *whole, char *part);
char		*ft_replace(char *str, const char *set, char ch);
int			count_occ_in_str(char *str, char ch);

int			find_max_row(t_list *headref);
void		append_char_to_lst(t_cub3D *game);
char		**convert_linked_list_to_array(t_list **headref);

void		verline(t_cub3D *game, int x);
void		calc_texture(t_cub3D *game);
void		calc_line_height(t_cub3D *game);
void		calc_tilepos(t_cub3D *game, double ray_dir_x, double ray_dir_y);

//COLORS
uint32_t	create_color(int red, int green, int blue);
int			paint_colors(mlx_image_t *image, int width, \
			int height, unsigned int color);

//RENDERS AND RAYS
void		set_ups(t_cub3D *game);
void		ray_cast_loop(t_cub3D *game);
void		render_floor(t_cub3D *game);
void		perform_dda(t_cub3D *game, double delta_dx, double delta_dy);
#endif