/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:43:23 by jischoi           #+#    #+#             */
/*   Updated: 2022/05/30 15:39:57 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_sign(char *p, int *sign)
{
	while ((*p >= 7 && *p <= 13) || *p == 32)
		p++;
	if (*p == '-' || *p == '+')
	{
		if (*p == '-')
			*sign *= -1;
		p++;
	}
	return (p);
}

int	ft_atoi(const char *nptr)
{
	long int	res;
	char		*p;
	int			sign;
	int			i;

	res = 0;
	p = (char *)nptr;
	i = 0;
	sign = 1;
	p = get_sign(p, &sign);
	while (p[i] >= '0' && p[i] <= '9')
	{
		res = res * 10 + (p[i] - '0');
		i++;
	}
	return (res * sign);
}
