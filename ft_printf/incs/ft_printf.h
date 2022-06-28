/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:31:32 by ljaehaer          #+#    #+#             */
/*   Updated: 2021/11/17 17:22:23 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *src, ...);
int		process_c_percent(char c);
int		process_s(char *s);
int		process_p(unsigned long num);
int		process_d_i(int num);
int		process_u(unsigned int num);
int		process_x(unsigned int num);
int		process_upper_x(unsigned int num);
char	*convert_to_hex_lower_p(unsigned long num);
char	*convert_to_hex_lower(unsigned int num);
char	*convert_to_hex_upper(unsigned int num);
#endif