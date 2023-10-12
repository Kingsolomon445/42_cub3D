/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:52:35 by sbhatta           #+#    #+#             */
/*   Updated: 2023/07/18 12:21:17 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_print_hex(unsigned long n, char ch, int *i, int fd)
{
	if (ch == 'u')
	{
		ft_putnbr_long(n, fd);
		*i += ft_printf_count(n);
	}
	else if ((n <= 15) && ch == 'x')
	{
		write(2, &("0123456789abcdef"[n]), fd);
		(*i)++;
	}
	else if ((n <= 15) && ch == 'X')
	{
		write(2, &("0123456789ABCDEF"[n]), fd);
		(*i)++;
	}
	else
	{
		ft_print_hex(n / 16, ch, i, fd);
		ft_print_hex(n % 16, ch, i, fd);
	}
}
