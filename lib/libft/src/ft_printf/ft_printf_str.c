/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:19:34 by sbhatta           #+#    #+#             */
/*   Updated: 2023/07/18 12:19:06 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_printf_str(int *i, char *str, int fd)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", fd);
		*i += 6;
	}
	else
	{
		ft_putstr_fd(str, fd);
		*i += ft_strlen(str);
	}
}
