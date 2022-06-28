/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:40:08 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/02/12 11:22:34 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	s2 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_process_line(char *buffer, char **line)
{
	char	*p_new_line;	
	char	*tmp;

	p_new_line = ft_strchr(buffer, '\n');
	tmp = ft_substr(buffer, 0, p_new_line - buffer + 1);
	*line = ft_strjoin2(*line, tmp);
	free(tmp);
	tmp = *line;
	if (ft_strlen(p_new_line) > 1)
		*line = ft_strdup(p_new_line + 1);
	else
		*line = NULL;
	return (tmp);
}

char	*ft_process_line_at_empty_buf(char **line)
{
	char	*p_new_line;	
	char	*tmp;
	char	*tmp2;

	p_new_line = ft_strchr(*line, '\n');
	tmp = ft_substr(*line, 0, p_new_line - (*line) + 1);
	if (ft_strlen(p_new_line) > 1)
	{
		tmp2 = ft_substr(*line, p_new_line - (*line) + 1,
				ft_strlen(p_new_line + 1));
		free(*line);
		*line = tmp2;
	}
	else
	{
		free(*line);
		*line = NULL;
	}
	return (tmp);
}

char	*multi_func(char **line, ssize_t read_bytes)
{
	char		*tmp;

	if (read_bytes < 0)
	{
		free(*line);
		*line = NULL;
		return (*line);
	}
	if (read_bytes == 0 && **line != '\0')
	{
		if (ft_strchr(*line, '\n'))
			return (ft_process_line_at_empty_buf(line));
		tmp = ft_strdup(*line);
		free(*line);
		*line = NULL;
		return (tmp);
	}
	free(*line);
	*line = NULL;
	return (*line);
}

char	*get_next_line(int fd)
{
	ssize_t		read_bytes;
	char		buffer[BUFFER_SIZE + 1];
	static char	*line = NULL;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (!line)
	{
		line = malloc(sizeof(char));
		*line = '\0';
	}
	if (ft_strchr(line, '\n'))
		return (ft_process_line_at_empty_buf(&line));
	while (1)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			return (multi_func(&line, read_bytes));
		if (ft_strchr(buffer, '\n'))
			return (ft_process_line(buffer, &line));
		line = ft_strjoin2(line, buffer);
	}
}
