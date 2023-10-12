/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:01:30 by sbhatta           #+#    #+#             */
/*   Updated: 2023/08/18 16:35:13 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_printf_fd(int fd, const char *str, ...)
{
	va_list		args;
	int			i;

	i = 0;
	va_start(args, str);
	while (*str != '\0' )
	{
		if (*str == '%')
		{
			str++;
			if (*str == 's')
				ft_printf_str(&i, va_arg(args, char *), fd);
			else if (*str == 'p' || *str == 'd' || *str == 'i' || *str == 'c')
				ft_printf_ptr((unsigned long)(va_arg(args, void *)), \
				&i, *str, fd);
			else if (*str == 'x' || *str == 'X' || *str == 'u')
				ft_print_hex(va_arg(args, unsigned int), *str, &i, fd);
			else if (*str == '%')
				ft_printf_perc(&i, fd);
		}
		else
			ft_printf_char(&i, *str, fd);
		str++;
	}
	return (va_end(args), i);
}
