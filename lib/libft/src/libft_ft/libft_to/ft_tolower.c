/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:49:35 by sbhatta           #+#    #+#             */
/*   Updated: 2023/04/08 13:28:48 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_islower(int a)
{
	if (a >= 65 && a <= 90)
		return (1);
	else
		return (0);
}

int	ft_tolower(int c)
{
	if (ft_islower(c) == 1)
		c = c + 32;
	return (c);
}
