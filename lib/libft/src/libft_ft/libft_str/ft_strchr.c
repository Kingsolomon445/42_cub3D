/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:57:02 by sbhatta           #+#    #+#             */
/*   Updated: 2023/06/15 14:11:47 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	char	*ptr;
	size_t	len;

	a = (char)c;
	ptr = NULL;
	len = ft_strlen((char *)s);
	if (a != '\0')
	{
		while (*s)
		{
			if (*s == a)
			{
				ptr = (char *)s;
				break ;
			}
			s++;
		}
	}
	else
		ptr = (char *)s + len;
	return (ptr);
}
