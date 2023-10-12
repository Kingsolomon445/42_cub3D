/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:41:10 by sbhatta           #+#    #+#             */
/*   Updated: 2023/10/07 10:18:04 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;
	int	s1len;
	int	s2len;

	i = 0;
	s1len = (int)ft_strlen((char *)s1);
	s2len = (int)ft_strlen((char *)s2);
	if (n == 0)
		return (0);
	if ((unsigned char)s1[i] == '\0' || n < 0)
		return (-(unsigned char)s2[i]);
	else if ((unsigned char)s2[i] == '\0')
		return ((unsigned char)s1[i]);
	if ((n >= s1len && s1len >= s2len) || (n > s2len && s2len <= s1len))
		n = s1len;
	else if ((n >= s2len && s2len >= s1len) || (n > s1len && s1len <= s2len))
		n = s2len;
	while (n-- != 0)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
