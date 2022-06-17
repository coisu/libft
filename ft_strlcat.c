/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:16:09 by jischoi           #+#    #+#             */
/*   Updated: 2022/05/25 12:31:50 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

unsigned int	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	size_t			destlen;
	size_t			srclen;

	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	while (destlen + i < size - 1 && src[i])
	{
		dest[destlen + i] = src[i];
		i++;
	}
	if (i != 0)
		dest[destlen + i] = 0;
	if (destlen < size)
		return (destlen + srclen);
	return (srclen + size);
}
