# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 13:18:59 by sbhatta           #+#    #+#              #
#    Updated: 2023/10/03 13:57:49 by ofadahun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wextra -Werror -Wall -g
AR = ar
CRS = crs
NAME = libft.a

SRC = 	./src/libft_ft/libft_to/ft_itoa.c ./src/libft_ft/libft_to/ft_atoi_ulong.c ./src/libft_ft/libft_to/ft_atoi.c ./src/libft_ft/libft_to/ft_toupper.c ./src/libft_ft/libft_to/ft_tolower.c ./src/libft_ft/libft_to/ft_atoi_long.c ./src/libft_ft/libft_is/ft_isspace.c \
		./src/libft_ft/libft_mem/ft_calloc.c ./src/libft_ft/libft_mem/ft_bzero.c ./src/libft_ft/libft_mem/ft_memcpy.c \
		./src/libft_ft/libft_mem/ft_memset.c ./src/libft_ft/libft_mem/ft_memchr.c ./src/libft_ft/libft_mem/ft_memmove.c ./src/libft_ft/libft_mem/ft_memcmp.c \
		./src/libft_ft/libft_put/ft_putchar_fd.c ./src/libft_ft/libft_put/ft_putstr_fd.c ./src/libft_ft/libft_put/ft_putendl_fd.c ./src/libft_ft/libft_put/ft_putnbr_fd.c \
		./src/libft_ft/libft_is/ft_isdigit.c ./src/libft_ft/libft_is/ft_isalnum.c ./src/libft_ft/libft_is/ft_isalpha.c  ./src/libft_ft/libft_is/ft_isascii.c ./src/libft_ft/libft_is/ft_isprint.c ./src/libft_ft/libft_is/ft_isnumber.c\
		./src/libft_ft/libft_str/ft_strlen.c ./src/libft_ft/libft_str/ft_strlcat.c ./src/libft_ft/libft_str/ft_strlcpy.c ./src/libft_ft/libft_str/ft_strchr.c \
		./src/libft_ft/libft_str/ft_strrchr.c ./src/libft_ft/libft_str/ft_strnstr.c ./src/libft_ft/libft_str/ft_strtrim.c ./src/libft_ft/libft_str/ft_strncmp.c \
		./src/libft_ft/libft_str/ft_substr.c ./src/libft_ft/libft_str/ft_split.c ./src/libft_ft/libft_str/ft_strmapi.c ./src/libft_ft/libft_str/ft_count_str_array.c \
		./src/libft_ft/libft_str/ft_strjoin.c ./src/libft_ft/libft_str/ft_striteri.c ./src/libft_ft/libft_str/ft_strdup.c \
		./src/libft_ft/libft_list/ft_lstadd_front.c ./src/libft_ft/libft_list/ft_lstnew.c ./src/libft_ft/libft_list/ft_lstadd_back.c \
		./src/libft_ft/libft_list/ft_lstsize.c ./src/libft_ft/libft_list/ft_lstlast.c ./src/libft_ft/libft_list/ft_lstdelone.c \
		./src/libft_ft/libft_list/ft_lstclear.c ./src/libft_ft/libft_list/ft_lstiter.c ./src/libft_ft/libft_list/ft_lstfree.c\
		./src/ft_printf/ft_printf.c ./src/ft_printf/ft_print_hex.c ./src/ft_printf/ft_putnbr_long.c \
		./src/ft_printf/ft_printf_char.c ./src/ft_printf/ft_printf_str.c ./src/ft_printf/ft_printf_ptr.c \
		./src/ft_printf/ft_printf_count.c ./src/ft_printf/ft_printf_perc.c \
		./src/get_next_line/get_next_line.c ./src/free/ft_free_int_array.c ./src/free/ft_free_split.c ./src/free/ft_free.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(CRS) $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean: 	
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re:	fclean all

.PHONY:	all clean fclean re bonus