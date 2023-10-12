/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:58:02 by sbhatta           #+#    #+#             */
/*   Updated: 2023/10/07 10:18:25 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

static int	ft_atoi_sup(const char *str, int i)
{
	int	digit;
	int	result;

	digit = 0;
	result = 0;
	while ((char)str[i] != '\0')
	{
		if ((char)str[i] == '-' || (char)str[i] == '+')
			break ;
		else if (ft_isspace((char)str[i]) == 1)
			break ;
		else
		{
			if ((char)str[i] >= '0' && (char)str[i] <= '9')
				digit = (char)str[i] - '0';
			else
				break ;
			if (digit > 9)
				break ;
			result = 10 * result + digit;
			i++;
		}
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		result;
	int		i;

	sign = 0;
	result = 0;
	i = 0;
	while (ft_isspace((char)str[i]) == 1)
		i++;
	if ((char)str[i] == '-')
	{
		sign = 1;
		i++;
	}
	else if ((char)str[i] == '+')
	{
		sign = 0;
		i++;
	}
	result = ft_atoi_sup(str, i);
	if (sign == 1)
		return (-result);
	return (result);
}
