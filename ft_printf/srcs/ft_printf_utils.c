/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:27:22 by ljaehaer          #+#    #+#             */
/*   Updated: 2021/11/17 16:54:27 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"
#include "../incs/libft.h"

int	process_c_percent(char c)
{
	return (ft_putchar_fd(c, 1));
}

int	process_s(char *s)
{
	return (ft_putstr_fd(s, 1));
}

int	process_p(unsigned long num)
{
	char	*strnum;
	int		len;

	strnum = convert_to_hex_lower_p(num);
	len = ft_putstr_fd(strnum, 1);
	free(strnum);
	return (len);
}

int	process_d_i(int num)
{
	return (ft_putnbr_fd(num, 1));
}

int	process_u(unsigned int num)
{
	return (ft_putnbr_u_fd(num, 1));
}
