/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:07:32 by ofadahun          #+#    #+#             */
/*   Updated: 2023/10/07 15:44:25 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_map(t_list *headref)
{
	t_list	*current;

	current = headref;
	while (current)
	{
		printf("%s<---->\n", (char *)current->content);
		current = current->next;
	}
}

void	print_array(char **arr)
{
	int	i;

	i = 0;
	printf("printing array of maps\n\n");
	while (arr[i])
	{
		printf("%s<---->\n", arr[i]);
		i++;
	}
	printf("printing array of maps ends\n\n");
}

void	ft_print_int_array(int **map, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			printf("%d", map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}
