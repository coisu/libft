/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:59:28 by jischoi           #+#    #+#             */
/*   Updated: 2022/05/31 16:13:04 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if ((size * nmemb) / size != nmemb)
		return (NULL);
	p = (char *)malloc(sizeof(*p) * (nmemb * size));
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}
