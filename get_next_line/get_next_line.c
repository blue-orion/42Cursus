/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:59:14 by takwak            #+#    #+#             */
/*   Updated: 2024/10/27 22:03:25 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*ft_realloc(char *ori, int memsize)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(sizeof(char) * (memsize + 1));
	i = 0;
	if (ori == NULL)
	{
		*(tmp + i) = '\0';
		return (tmp);
	}
	while (*ori)
		*(tmp + i++) = *(ori++);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	static int	buf_idx;
	char		*line;
	int			line_idx;
	int			read_size;
	int			total_size;
	int			i;

	line = NULL;
	line_idx = 0;
	total_size = 0;
	if (buf == NULL)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		line = NULL;
	}
	else
	{
		line = (char *)malloc(sizeof(char) * (BUFFER_SIZE - buf_idx + 1));
		while (*(buf + buf_idx))
			*(line + line_idx++) = *(buf + buf_idx++);
		total_size = line_idx;
		*(line + line_idx) = '\0';
	}
	read_size = 1;
	while (read_size != 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
		if (read_size == 0)
			break ;
		i = 0;
		while (*(buf + i) != '\n' && i < BUFFER_SIZE)
			i++;
		total_size += i;
		line = ft_realloc(line, total_size);
		buf_idx = 0;
		while (*(buf + buf_idx) != '\n' && buf_idx < BUFFER_SIZE)
			line[line_idx++] = buf[buf_idx++];
		line[line_idx] = '\0';
		if (*(buf + buf_idx) == '\n')
		{
			buf_idx++;
			line[line_idx] = '\n';
			return (line);
		}
	}
	return (NULL);
}
