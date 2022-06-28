/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_check_error2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 23:30:11 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/02/13 21:04:03 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	process_first_str(char *map, char *line)
{
	int	i;

	i = 0;
	while (line[i] == '1')
		i++;
	if (line[i] != '\n')
		print_error_with_free2("The map is not surrounded by walls", map, line);
}

char	*search_penult_nl(char *map)
{
	int	len;

	len = map + ft_strlen(map) - 3 - map;
	while (len >= 0)
	{
		if (map[len] == '\n')
			return (&map[len]);
		len--;
	}
	return (NULL);
}

void	process_last_str(char *map, int *count_chars)
{
	char	*p_new_line;

	if (ft_strlen(map) < 18)
		print_error_with_free("The map width and/or height too small", map);
	p_new_line = search_penult_nl(map);
	if (!p_new_line)
		print_error_with_free("The map width and/or height too small", map);
	p_new_line++;
	while (*p_new_line == '1')
		p_new_line++;
	if (*p_new_line != '\n')
		print_error_with_free("The map is not surrounded by walls", map);
	if (count_chars[0] == 0)
		print_error_with_free("The map does not contain an exit", map);
	if (count_chars[1] == 0)
		print_error_with_free("The map does not contain a collectible", map);
	if (count_chars[2] == 0)
		print_error_with_free("The map does not contain start position", map);
	if (count_chars[2] > 1)
		print_error_with_free("The map contains more than 1 starting position",
			map);
}

void	check_rectangular_map(char *map, char *line)
{
	static int	len = 0;
	int			i;

	if (!line)
		return ;
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (len != 0)
	{
		if (line[i] == '\0' || len != ++i)
			print_error_with_free2("The map is not rectangular", map, line);
	}
	else
		len = ++i;
}

void	check_valid_chars(char *map, char *line)
{
	static int	count_chars[] = {0, 0, 0};
	static int	count = 0;

	if (!line)
	{
		process_last_str(map, count_chars);
		return ;
	}
	if (count == 0)
	{
		count++;
		process_first_str(map, line);
		return ;
	}
	if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
		print_error_with_free2("The map is not surrounded by walls", map, line);
	if (ft_strchr(line, 'E'))
		count_chars[0]++;
	if (ft_strchr(line, 'C'))
		count_chars[1]++;
	if (ft_strchr(line, 'P'))
		count_chars[2]++;
	check_on_other_chars(map, line);
}
