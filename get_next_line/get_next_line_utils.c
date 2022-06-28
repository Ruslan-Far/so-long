/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:40:14 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/02/11 12:42:35 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *) s = '\0';
		s++;
		i++;
	}
}

char	*ft_strjoin2(char *s1, char const *s2)
{
	char		*str;
	size_t		i;
	size_t		len_s1;
	size_t		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len_s2)
		str[len_s1++] = s2[i++];
	str[len_s1] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dup;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s > len)
		dup = malloc(sizeof(char) * (len + 1));
	else
		dup = malloc(sizeof(char) * (len_s + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len && start < len_s)
		dup[i++] = s[start++];
	dup[i] = '\0';
	return (dup);
}

char	*ft_strchr(const char *str, int ch)
{
	ch %= 256;
	while (*str != '\0')
	{
		if (*str == ch)
			return ((char *) str);
		str++;
	}
	if (*str == ch)
		return ((char *) str);
	return (NULL);
}
