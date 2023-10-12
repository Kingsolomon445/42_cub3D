/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:13:28 by sbhatta           #+#    #+#             */
/*   Updated: 2023/06/15 13:44:35 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	m;

	i = 0;
	j = 0;
	m = len;
	if (!haystack && len == 0)
		return (NULL);
	if (!(*needle) || haystack == needle)
		return ((char *)haystack);
	while (len-- && i < ft_strlen((char *)haystack))
	{
		while (haystack[i + j] == needle[j] && haystack[i + j] != '\0' \
		&& i + j < m)
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
		j = 0;
	}
	return (NULL);
}
