/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:27:05 by jischoi           #+#    #+#             */
/*   Updated: 2022/05/31 17:01:17 by jischoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	ln;

	ln = n;
	if (fd >= 0)
	{
		if (ln < 0)
		{
			ft_putchar_fd('-', fd);
			ln *= -1;
		}
		while (ln > 9)
		{
			ft_putnbr_fd(ln / 10, fd);
			ln %= 10;
		}
		ft_putchar_fd(ln + '0', fd);
	}
}
