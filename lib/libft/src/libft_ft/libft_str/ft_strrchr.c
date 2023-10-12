/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:21:41 by sbhatta           #+#    #+#             */
/*   Updated: 2023/06/15 13:44:35 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	char	*ptr;
	size_t	len;

	a = (char)c;
	len = ft_strlen((char *)s);
	ptr = NULL;
	if (a != '\0')
	{
		while (*s)
		{
			if ((char)*s == a)
				ptr = (char *)s;
			s++;
		}
	}
	else
		ptr = (char *)s + len;
	return (ptr);
}
