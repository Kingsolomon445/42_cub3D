/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:58:25 by ofadahun          #+#    #+#             */
/*   Updated: 2023/10/07 13:59:23 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	count_occurences(t_list *headref, char ch)
{
	t_list	*current;
	char	*line;
	int		occ;
	int		i;

	occ = 0;
	current = headref;
	while (current)
	{
		i = 0;
		line = current->content;
		while (*(line + i))
		{
			if (*(line + i) == ch)
				occ++;
			i++;
		}
		current = current->next;
	}
	return (occ);
}

int	count_occ_in_str(char *str, char ch)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == ch)
			cnt++;
		i++;
	}
	return (cnt);
}

int	starts_with(char *whole, char *part)
{
	int	i;

	i = 0;
	while (part[i])
	{
		if (part[i] != whole[i])
			return (0);
		i++;
	}
	return (1);
}

int	ends_with(char *whole, char *part)
{
	int	i;
	int	j;

	i = ft_strlen(whole) - 1;
	j = ft_strlen(part) - 1;
	while (j >= 0)
	{
		if (part[j] != whole[i])
			return (0);
		j--;
		i--;
	}
	return (1);
}

char	*ft_replace(char *str, const char *set, char ch)
{
	int		i;
	char	*new_str;

	new_str = malloc(ft_strlen(str) + 1);
	if (!new_str)
		return (ft_free(str), NULL);
	i = 0;
	while (str[i])
	{
		if (ft_strchr(set, str[i]))
			new_str[i] = ch;
		else
			new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	ft_free(str);
	return (new_str);
}
