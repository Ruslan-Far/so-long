/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:54:28 by ljaehaer          #+#    #+#             */
/*   Updated: 2021/11/17 17:11:51 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int	ft_putnbr_u_fd(unsigned int n, int fd)
{
	char	s[12];
	int		i;

	s[11] = '\0';
	i = 10;
	if (n == 0)
		return (write(fd, "0", 1));
	while (n > 0)
	{
		s[i--] = n % 10 + '0';
		n /= 10;
	}
	i++;
	return (write(fd, &s[i], ft_strlen(&s[i])));
}
