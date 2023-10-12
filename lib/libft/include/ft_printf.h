/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:44:34 by sbhatta           #+#    #+#             */
/*   Updated: 2023/10/02 11:32:24 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		ft_printf_fd(int fd, const char *str, ...);
void	ft_print_hex(unsigned long n, char ch, int *i, int fd);
void	ft_putnbr_long(long n, int fd);
void	ft_printf_char(int *i, char c, int fd);
void	ft_printf_str(int *i, char *str, int fd);
void	ft_printf_ptr(unsigned long p, int *i, char ch, int fd);
int		ft_printf_count(long n);
void	ft_printf_perc(int *i, int fd);
char	*get_next_line(int fd);
void	ft_free(void *ptr);
void	ft_free_split(char **str);
void	ft_free_int_array(int **arr, int rows);

#endif