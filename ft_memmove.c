/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:14:49 by jischoi           #+#    #+#             */
/*   Updated: 2022/05/24 17:20:22 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dstp;
	char	*srcp;

	dstp = (char *)dest;
	srcp = (char *)src;
	if (dest < src)
	{
		i = -1;
		while (++i < n)
			dstp[i] = srcp[i];
	}
	else if (dest > src)
	{
		i = n;
		while (i--)
			dstp[i] = srcp[i];
	}
	else if (dest == src || n == 0)
		return (dest);
	return (dest);
}
