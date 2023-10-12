/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:30:37 by sbhatta           #+#    #+#             */
/*   Updated: 2023/06/15 13:44:35 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

static int	ft_intlen(int n)
{
	int	count;

	count = 1;
	if (n >= 0 && n <= 9)
		return (1);
	while (n > 9)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static int	ft_lencalc(int n, long ln)
{
	int	mlen;

	mlen = 0;
	if (ln == 2147483648)
		mlen = 10;
	else
		mlen = ft_intlen(ln);
	if (n < 0)
		mlen = mlen + 1;
	return (mlen);
}

static int	ft_checkneg(int n, int nlen, char *result)
{
	if (n < 0)
	{
		result[0] = '-';
		nlen = nlen - 1;
	}
	return (nlen);
}

char	*ft_itoa(int n)
{
	int		nlen;
	char	*result;
	long	ln;
	int		max;

	ln = n;
	if (n < 0)
		ln = -ln;
	nlen = ft_lencalc(n, ln);
	max = nlen;
	result = (char *)malloc((nlen + 1) * sizeof(char));
	if (!result)
		return (NULL);
	nlen = ft_checkneg(n, nlen, result);
	while ((nlen) != 0)
	{
		if (n < 0)
			result[nlen] = (ln % 10) + '0';
		else
			result[nlen - 1] = (ln % 10) + '0';
		ln = ln / 10;
		nlen--;
	}
	result[max] = '\0';
	return (result);
}
