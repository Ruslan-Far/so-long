/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:36:54 by ljaehaer          #+#    #+#             */
/*   Updated: 2021/10/12 22:34:14 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

static int	process_neg(int n, int fd, char *s)
{
	int	i;

	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n == 0)
		return (write(fd, "0", 1));
	n = -n;
	s[11] = '\0';
	i = 10;
	while (n > 0)
	{
		s[i--] = n % 10 + '0';
		n /= 10;
	}
	s[i] = '-';
	return (write(fd, &s[i], ft_strlen(&s[i])));
}

int	ft_putnbr_fd(int n, int fd)
{
	char	s[12];
	int		i;

	if (n <= 0)
		return (process_neg(n, fd, s));
	s[11] = '\0';
	i = 10;
	while (n > 0)
	{
		s[i--] = n % 10 + '0';
		n /= 10;
	}
	i++;
	return (write(fd, &s[i], ft_strlen(&s[i])));
}
