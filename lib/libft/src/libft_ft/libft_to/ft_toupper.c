/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:16:24 by sbhatta           #+#    #+#             */
/*   Updated: 2023/04/08 13:28:54 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isupper(int a)
{
	if ((a >= 97 && a <= 122))
		return (1);
	else
		return (0);
}

int	ft_toupper(int c)
{
	if (ft_isupper(c) == 1)
		c = c - 32;
	return (c);
}
