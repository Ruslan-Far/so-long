/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 00:49:57 by ljaehaer          #+#    #+#             */
/*   Updated: 2021/11/17 16:47:47 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"
#include "../incs/libft.h"

static int	is_transfor(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	select_transfor(char transfor, va_list *args)
{
	if (transfor == 'c')
		return (process_c_percent((char) va_arg(*args, int)));
	else if (transfor == 's')
		return (process_s(va_arg(*args, char *)));
	else if (transfor == 'p')
		return (process_p(va_arg(*args, unsigned long)));
	else if (transfor == 'd' || transfor == 'i')
		return (process_d_i(va_arg(*args, int)));
	else if (transfor == 'u')
		return (process_u(va_arg(*args, unsigned int)));
	else if (transfor == 'x')
		return (process_x(va_arg(*args, unsigned int)));
	else if (transfor == 'X')
		return (process_upper_x(va_arg(*args, unsigned int)));
	else if (transfor == '%')
		return (process_c_percent('%'));
	else
		return (-1);
}

static int	search_percents(const char *src, va_list *args)
{
	int	end;
	int	len;

	end = 0;
	len = 0;
	while (src[end])
	{
		if (src[end] == '%')
		{
			if (is_transfor(src[++end]))
				len += select_transfor(src[end], args);
		}
		else
			len += ft_putchar_fd(src[end], 1);
		end++;
	}
	return (len);
}

int	ft_printf(const char *src, ...)
{
	va_list	args;
	int		len;

	va_start(args, src);
	len = search_percents(src, &args);
	va_end(args);
	return (len);
}
