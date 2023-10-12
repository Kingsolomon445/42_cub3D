/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:11:16 by sbhatta           #+#    #+#             */
/*   Updated: 2023/06/15 14:11:48 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

static int	ft_memcmp_result(unsigned char *s1, unsigned char *s2, size_t n)
{
	size_t			result;
	size_t			i;

	result = 0;
	i = 0;
	while (n-- != 0)
	{
		if (s1[i] < s2[i])
		{
			result = s2[i] - s1[i];
			if (!ft_isalnum(s1[i] && !ft_isalnum(s2[i])))
				result = -1 * result;
			break ;
		}
		else if (s2[i] < s1[i])
		{
			result = s1[i] - s2[i];
			if (!ft_isalnum(s1[i] && !ft_isalnum(s2[i])))
				result = 1 * result;
			break ;
		}
		i++;
	}
	return ((int)result);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1ptr;
	unsigned char	*s2ptr;
	int				result;

	s1ptr = (unsigned char *)s1;
	s2ptr = (unsigned char *)s2;
	result = ft_memcmp_result(s1ptr, s2ptr, n);
	return (result);
}
