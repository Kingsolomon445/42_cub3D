/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:29:58 by sbhatta           #+#    #+#             */
/*   Updated: 2023/06/15 14:11:01 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	count;

	len = ft_strlen((char *)src);
	count = 0;
	if (dstsize != 0)
	{
		while (count <= (dstsize - 2) && src[count] != '\0')
		{
			if (dstsize != 1)
			{
				dst[count] = src[count];
				count++;
			}
			else
				break ;
		}
		dst[count] = '\0';
	}
	return (len);
}
