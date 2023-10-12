/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:55:04 by sbhatta           #+#    #+#             */
/*   Updated: 2023/06/15 13:44:35 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	slen;
	size_t	atual_len;

	if (!s)
		return (0);
	slen = ft_strlen((char *)s);
	if (start >= slen)
	{
		result = ft_strdup("");
		if (!result)
			return (0);
		return (result);
	}
	atual_len = slen - start;
	result = NULL;
	if (len > atual_len)
		len = atual_len;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (0);
	else
		ft_strlcpy(result, s + start, len + 1);
	return (result);
}
