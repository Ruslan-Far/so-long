/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:31:00 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/02/13 22:11:04 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static char	*init(int *fd, char *file_map)
{
	char	*map;

	check_extension_fmap(file_map);
	*fd = open(file_map, O_RDONLY);
	check_access_fmap(fd, file_map);
	map = malloc(sizeof(char));
	*map = '\0';
	return (map);
}

char	*read_map(char *file_map)
{
	int		fd;
	char	*line;
	char	*map;
	char	*tmp;

	map = init(&fd, file_map);
	while (1)
	{
		line = get_next_line(fd);
		check_rectangular_map(map, line);
		check_valid_chars(map, line);
		if (!line)
			break ;
		tmp = ft_strjoin(map, line);
		free(line);
		free(map);
		map = tmp;
	}
	close(fd);
	return (map);
}
