/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:27:00 by sbhatta           #+#    #+#             */
/*   Updated: 2023/06/15 14:11:20 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	a;
	unsigned char	*ptr;
	unsigned char	*str;

	a = (unsigned char)c;
	ptr = NULL;
	str = (unsigned char *)s;
	while (n != 0)
	{
		if (*str == a)
		{
			ptr = str;
			break ;
		}
		n--;
		str++;
	}
	return ((void *)ptr);
}
