/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:06:12 by jischoi           #+#    #+#             */
/*   Updated: 2022/05/27 15:21:41 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_issign(char *a, long int n)
{
	if (n < 0)
	{
		a[0] = '-';
		n *= -1;
	}
	return (n);
}

int	get_ilen(long int n)
{
	int	i;

	if (n <= 0)
		i = 1;
	else
		i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*a;
	int			ilen;
	long int	num;

	ilen = get_ilen(n);
	a = (char *)malloc(sizeof(char) * (ilen + 1));
	if (!a)
		return (NULL);
	a[ilen] = 0;
	num = (unsigned)ft_issign(a, n);
	while (ilen-- > 0 || num == 0)
	{
		a[ilen] = (num % 10) + '0';
		num /= 10;
		if (num == 0)
			break ;
	}
	return (a);
}
