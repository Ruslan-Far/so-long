/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_check_error3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:49:43 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/02/13 21:02:14 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	check_on_other_chars(char *map, char *line)
{
	int	i;

	i = 0;
	while (line[i] == '0' || line[i] == '1' || line[i] == 'C'
		|| line[i] == 'E' || line[i] == 'P')
		i++;
	if (line[i] != '\n')
		print_error_with_free2("The map contains invalid characters",
			map, line);
}
