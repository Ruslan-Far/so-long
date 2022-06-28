/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:07:02 by ljaehaer          #+#    #+#             */
/*   Updated: 2021/11/17 17:07:51 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"
#include "../incs/libft.h"

static int	get_hex_len_p(unsigned long num)
{
	int		len;

	len = 0;
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	if (len == 0)
		return (1);
	return (len);
}

char	*convert_to_hex_lower_p(unsigned long num)
{
	int				len;
	char			*strnum;
	unsigned long	tmp;

	len = get_hex_len_p(num) + 2;
	strnum = malloc(sizeof(char) * (len + 1));
	if (!strnum)
		return (NULL);
	strnum[len] = '\0';
	if (num == 0)
		strnum[--len] = '0';
	while (num != 0)
	{
		tmp = num % 16;
		if (tmp > 9 && tmp < 16)
			tmp += 87;
		else
			tmp += '0';
		strnum[--len] = tmp;
		num /= 16;
	}
	strnum[--len] = 'x';
	strnum[--len] = '0';
	return (strnum);
}
