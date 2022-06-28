/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 00:26:13 by ljaehaer          #+#    #+#             */
/*   Updated: 2021/11/17 17:19:00 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"
#include "../incs/libft.h"

int	process_x(unsigned int num)
{
	char	*strnum;
	int		len;

	strnum = convert_to_hex_lower(num);
	len = ft_putstr_fd(strnum, 1);
	free(strnum);
	return (len);
}

int	process_upper_x(unsigned int num)
{
	char	*strnum;
	int		len;

	strnum = convert_to_hex_upper(num);
	len = ft_putstr_fd(strnum, 1);
	free(strnum);
	return (len);
}

static int	get_hex_len(unsigned int num)
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

char	*convert_to_hex_lower(unsigned int num)
{
	int				len;
	char			*strnum;
	unsigned int	tmp;

	len = get_hex_len(num);
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
	return (strnum);
}

char	*convert_to_hex_upper(unsigned int num)
{
	int				len;
	char			*strnum;
	unsigned int	tmp;

	len = get_hex_len(num);
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
			tmp += 55;
		else
			tmp += '0';
		strnum[--len] = tmp;
		num /= 16;
	}
	return (strnum);
}
