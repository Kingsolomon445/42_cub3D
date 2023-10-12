/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:34:44 by sbhatta           #+#    #+#             */
/*   Updated: 2023/06/20 12:40:33 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

static char	*ft_increment(char *str, char c)
{
	while (*str == c && *str)
		str++;
	return (str);
}

static int	ft_counter(char *str, char c)
{
	int	count;

	count = 0;
	str = ft_increment(str, c);
	while (*str != 0)
	{
		if (*str == c)
		{
			str = ft_increment(str, c);
			if (*str != c && *str != '\0')
				count++;
		}
		if (*str != '\0')
			str++;
	}
	return (count);
}

static char	**ft_freemem(char **result, int i, const char *s, char c)
{
	if (i == 0)
	{
		if (s == NULL)
			return (NULL);
		if (!*s || (!*(ft_increment((char *)s, c))))
		{
			result = (char **)malloc((1) * sizeof(char *));
			if (!result)
				return (0);
			*result = 0;
			return (result);
		}
	}
	i--;
	while (i >= 0)
	{
		free(result[i]);
		result[i] = 0;
		i--;
	}
	free(result);
	return (NULL);
}

static char	*ft_split_operation(char *str, char c)
{
	char	*end;
	int		len;
	char	*final;

	len = 0;
	if (ft_counter(str, c) != 0)
	{
		end = ft_strchr(str, c);
		len = end - str;
	}
	else
	{
		end = str + ft_strlen(str);
		while (*(--end) && *end == c)
			continue ;
		len = end - str + 1;
	}
	final = (char *)malloc(len + 1);
	if (!final)
		return (0);
	ft_strlcpy(final, str, len + 1);
	return (final);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		i;
	char	*str;
	char	**result;

	i = 0;
	result = NULL;
	if (s == NULL || !*s || (!*(ft_increment((char *)s, c))))
		return (ft_freemem(result, i, s, c));
	str = (char *)s;
	count = ft_counter(str, c) + 1;
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (!result)
		return (0);
	while (count-- != 0)
	{
		str = ft_increment(str, c);
		result[i] = ft_split_operation((str), c);
		if (!result[i])
			return (ft_freemem(result, i, s, c));
		str = str + (ft_strchr(str, c) - str);
		i++;
	}
	result[i] = 0;
	return (result);
}
