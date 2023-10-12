/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_surrounded_by_wall.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:09:35 by ofadahun          #+#    #+#             */
/*   Updated: 2023/10/12 12:06:53 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	is_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	is_surrounded_by_wall(t_list *headref)
{
	t_list	*current;
	t_list	*last;

	last = ft_lstlast(headref);
	if (!is_wall(headref->content) || !is_wall(last->content))
		return (0);
	current = headref;
	while (current)
	{
		if (!ft_strchr("1 \t\v\b", *(char *)(current->content)) || \
		!ft_strchr("1 \t\v\b", *(char *)(current->content + \
		ft_strlen(current->content) - 1)))
			return (0);
		current = current->next;
	}
	return (1);
}
