/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:52:44 by sbhatta           #+#    #+#             */
/*   Updated: 2023/06/16 16:37:47 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	result = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, (s1len + 1));
	ft_strlcat(result + s1len, s2, (s2len + s1len + 1));
	return (result);
}
