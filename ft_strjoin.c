/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:46:23 by jischoi           #+#    #+#             */
/*   Updated: 2022/06/09 16:42:32 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	size;

	i = -1;
	j = -1;
	if (!*(s1) && !*(s2))
		return (ft_strdup(""));
	if ((!(s1) && !(s2)))
		return (NULL);
	if ((!*(s1) && *(s2)) || (!(s1) && (s2)))
		return (ft_strdup(s2));
	if ((*(s1) && !*(s2)) || ((s1) && !(s2)))
		return (ft_strdup(s1));
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}
