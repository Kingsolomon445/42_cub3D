/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:45:28 by sbhatta           #+#    #+#             */
/*   Updated: 2023/06/15 13:14:40 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static void	ft_free_gnl(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
}

static char	*ft_strjoin_gnl(char *result, char	*buffer_to_add)
{
	char	*result_join;
	size_t	s1len;
	size_t	s2len;

	if (!result)
	{
		result = malloc(1);
		if (!result)
			return (0);
		*result = '\0';
	}
	s1len = ft_strlen(result);
	s2len = ft_strlen(buffer_to_add);
	result_join = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (!result_join)
		return (ft_free_gnl(result), NULL);
	ft_strlcpy(result_join, result, (s1len + 1));
	ft_strlcat(result_join, buffer_to_add, (s2len + s1len + 1));
	free(result);
	return (result_join);
}

static char	*ft_no_newline(char *buffer, char *result, int fd, int *read_bytes)
{
	while (!ft_strchr(buffer, '\n'))
	{
		result = ft_strjoin_gnl(result, buffer);
		if (!result)
			return (NULL);
		ft_memset(buffer, 0, ft_strlen(buffer) + 1);
		*read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (*read_bytes == 0)
			return (result);
		else if (*read_bytes == -1)
			return (ft_free_gnl(result), NULL);
		buffer[*read_bytes] = '\0';
	}
	return (result);
}

static char	*ft_return_line(char *buffer, char *result, int fd, int read_bytes)
{
	char	*end;
	char	*to_join;

	if (!ft_strchr(buffer, '\n'))
	{
		result = ft_no_newline(buffer, result, fd, &read_bytes);
		if (read_bytes == 0)
			return (result);
		else if (read_bytes == -1)
			return (ft_free_gnl(result), NULL);
	}
	end = ft_strchr(buffer, '\n');
	to_join = malloc(end - buffer + 2);
	if (!to_join)
		return (NULL);
	ft_strlcpy(to_join, buffer, end - buffer + 2);
	result = ft_strjoin_gnl(result, to_join);
	free(to_join);
	if (!result)
		return (NULL);
	ft_memset(buffer, 0, end - buffer);
	ft_strlcpy(buffer, end + 1, ft_strlen(end) + 1);
	return (result);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	int				read_bytes;
	char			*result;

	if (BUFFER_SIZE < 1)
		return (NULL);
	result = NULL;
	read_bytes = 0;
	if (!*buffer)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			return (NULL);
		buffer[read_bytes] = '\0';
	}
	return (ft_return_line(buffer, result, fd, read_bytes));
}
