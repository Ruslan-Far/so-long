/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_check_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:35:20 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/02/12 11:53:33 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	print_error(char *error)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error, 2);
	exit(0);
}

void	print_error_with_free(char *error, char *map)
{
	free(map);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error, 2);
	exit(0);
}

void	print_error_with_free2(char *error, char *map, char *line)
{
	free(map);
	free(line);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error, 2);
	exit(0);
}

void	check_extension_fmap(char *file_map)
{
	char	*dot;

	dot = ft_strchr(file_map, '.');
	if (!dot)
		print_error("The file map extension not set");
	if (ft_strncmp(dot + 1, "ber", 4) != 0)
		print_error("The file map extension must be \"*.ber\"");
}

void	check_access_fmap(int *fd, char *file_map)
{
	if (*fd < 0)
	{
		ft_putendl_fd("Error", 2);
		perror(file_map);
		close(*fd);
		exit(0);
	}
}
