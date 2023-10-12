/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:28:36 by sbhatta           #+#    #+#             */
/*   Updated: 2023/07/18 12:24:36 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_printf_ptr(unsigned long p, int *i, char ch, int fd)
{
	if (ch == 'c')
	{
		ft_putchar_fd(p, fd);
		(*i)++;
	}
	else if (ch == 'i' || ch == 'd')
	{
		ft_putnbr_fd((int)p, fd);
		*i += ft_printf_count((int)p);
	}
	else
	{
		ft_putstr_fd("0x", fd);
		ft_print_hex(p, 'x', i, fd);
		*i += 2;
	}
}
