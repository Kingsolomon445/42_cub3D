# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 13:18:59 by sbhatta           #+#    #+#              #
#    Updated: 2023/10/08 12:47:05 by ofadahun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wextra -Werror -Wall -g
AR = ar
CRS = crs
NAME = cub3D
LIBFT_PATH = ./lib/libft
LIBFT = $(LIBFT_PATH)/libft.a
OBJ_DIR = ./obj
SRC_DIR = ./src
INC_DIR = -I ./include

MLX42_GIT = https://github.com/codam-coding-college/MLX42.git
MLX42_DIR = ./lib/MLX42
MLX42 = $(MLX42_DIR)/build/libmlx42.a
LD_FLAGS = -lglfw -lm

GREEN = \033[1;32m
WHITE = \033[0m
RED = \033[0;31m

MAIN = hooks init main movement
PARSER = parser/has_valid_path parser/is_data_valid parser/is_map_valid parser/is_rgb_valid parser/is_surrounded_by_wall parser/parse_map
RENDER = render/calc_tex render/cast_ray render/draw_utils render/floor render/set_ups render/dda
UTILS = utils/free_utils utils/lst_utils utils/map_utils utils/print_utils utils/str_utils

SOURCES = $(addsuffix .c, $(MAIN) $(PARSER) $(RENDER) $(UTILS))
SRC = $(addprefix $(SRC_DIR)/, $(SOURCES))
OBJ = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

.PHONY: all clean fclean re norm

all: $(NAME)

$(NAME): $(MLX42) $(OBJ) $(LIBFT)
	$(CC) -o $@ $^ $(LD_FLAGS)
	@echo "$(GREEN)Cub3D is ready 👍$(WHITE)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(MLX42_DIR):
	git clone $(MLX42_GIT) $(MLX42_DIR)

$(MLX42): $(MLX42_DIR)
	(cd $(MLX42_DIR) && cmake -B build && cmake --build build -j4)

$(LIBFT):
	@make all -C $(LIBFT_PATH)

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(MLX42_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)
	@echo "$(GREEN)The project is cleaned! 🗑️$(WHITE)"

re: fclean all

norm:
	norminette ./src ./include ./lib/libft
