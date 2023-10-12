/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:58:10 by ofadahun          #+#    #+#             */
/*   Updated: 2023/10/07 10:25:56 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	find_max_row(t_list *headref)
{
	int		max_row;
	int		row_len;
	t_list	*current;

	max_row = 0;
	current = headref;
	while (current)
	{
		row_len = ft_strlen((char *)current->content);
		if (row_len > max_row)
			max_row = row_len;
		current = current->next;
	}
	return (max_row);
}

char	**convert_linked_list_to_array(t_list **headref)
{
	int		col_size;
	int		col;
	char	**arr;
	t_list	*current;

	col_size = ft_lstsize(*headref);
	col = 0;
	arr = malloc(sizeof(char *) * (col_size + 1));
	current = *headref;
	while (col < col_size)
	{
		arr[col] = ft_strdup((char *)current->content);
		col++;
		current = current->next;
	}
	arr[col] = NULL;
	return (arr);
}

static char	*append_and_alloc(char *line)
{
	char	*new_line;
	int		i;
	int		j;

	new_line = malloc(ft_strlen(line) + 4);
	new_line[0] = 'V';
	new_line[ft_strlen(line) + 1] = 'V';
	new_line[ft_strlen(line) + 2] = '\0';
	i = 0;
	j = 1;
	while (line[i])
	{
		new_line[j] = line[i];
		i++;
		j++;
	}
	ft_free(line);
	return (new_line);
}

void	append_char_to_lst(t_cub3D *game)
{
	int		i;
	int		size;
	char	*new_line;

	i = 0;
	size = ft_lstsize(game->map_headref_copy);
	while (i < size)
	{
		new_line = ft_replace(game->copy_map[i], " \t\n\b\f\v", '0');
		game->copy_map[i] = append_and_alloc(new_line);
		i++;
	}
}
