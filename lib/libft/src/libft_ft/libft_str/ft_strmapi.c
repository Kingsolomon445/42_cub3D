/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:34:19 by sbhatta           #+#    #+#             */
/*   Updated: 2023/06/15 13:44:35 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	size_t			slen;
	unsigned int	i;

	i = 0;
	if (s)
	{
		slen = ft_strlen(s);
		result = (char *)malloc((slen + 1) * sizeof(char));
		if (!result)
			return (0);
		ft_strlcpy(result, s, slen + 1);
		while (result[i] != '\0')
		{
			result[i] = (*f)(i, result[i]);
			i++;
		}
		return (result);
	}
	else
		return (0);
}
