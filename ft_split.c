/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:54:54 by jischoi           #+#    #+#             */
/*   Updated: 2022/05/30 18:29:46 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*put_string(char const *s, char c, int num, int len)
{
	char	*str;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (count < num && s[i])
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1])
			|| ((i == 0) && (s[i] != c)))
			count++;
		if (num == 1 && s[i] != c)
			break ;
		i++;
	}
	while (j < len)
		str[j++] = s[i++];
	str[j] = 0;
	return (str);
}
/*
static int	get_count(char const *s, char c, int len)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && count == len - 1)
			j++;
		if (s[i] == c && ((s[i - 1] != c) && (s[i - 1])))
		{
			count++;
			if (len && count == len && s[i])
				return (j);
		}
		i++;
	}
	write(1,"t\n",2);
	if (s[i - 1] != c)
		count++;
	if (len)
		return (j);
	return (count);
}
*/

static int	get_count(char const *s, char c, int len)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && count == len - 1)
			j++;
		if ((s[i + 1] == c || s[i + 1] == '\0') == 1
			&& (s[i] == c || s[i] == '\0') == 0)
		{
			count++;
			if (len && count == len && s[i])
				return (j);
		}
		i++;
	}
	if (len)
		return (j);
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		len;
	int		wcount;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	wcount = get_count(s, c, 0);
	split = (char **)malloc(sizeof(char *) * (wcount + 1));
	if (!split)
		return (NULL);
	while (i < wcount)
	{
		len = get_count(s, c, i + 1);
		split[i] = put_string(s, c, i + 1, len);
		i++;
	}
	split[i] = (NULL);
	return (split);
}
