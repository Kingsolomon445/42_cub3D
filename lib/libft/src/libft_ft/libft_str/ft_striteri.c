/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:12:44 by sbhatta           #+#    #+#             */
/*   Updated: 2023/06/15 13:44:35 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t			slen;
	unsigned int	i;

	i = 0;
	if (s)
	{
		slen = ft_strlen(s);
		while (i != slen)
		{
			(*f)(i, s);
			i++;
			s++;
		}
	}
}
