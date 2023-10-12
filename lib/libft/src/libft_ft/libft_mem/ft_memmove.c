/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:30:25 by sbhatta           #+#    #+#             */
/*   Updated: 2023/06/15 14:11:48 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dstr;
	unsigned char	*sstr;

	dstr = (unsigned char *)dst;
	sstr = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dstr < sstr)
	{
		while (len--)
			*(dstr++) = *(sstr++);
	}
	else
	{
		dstr = dstr + len;
		sstr = sstr + len;
		while (len--)
		{
			dstr--;
			sstr--;
			*dstr = *sstr;
		}
	}
	return (dst);
}
