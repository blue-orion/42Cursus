#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*ft_realloc(char *ori, int memsize)
{
	char	*tmp;
	int		i;

	tmp = (char *)calloc(memsize + 1, sizeof(char));
	i = 0;
	if (ori == NULL)
		return (tmp);
	while (*ori)
		tmp[i++] = *(ori++);
	free(ori);
	return (tmp);
}

#include <string.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*buf;
	int		buf_idx;
	char	*line;
	int		line_idx;
	int		read_size;
	int		total_size;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	line = NULL;
	line_idx = 0;
	read_size = 1;
	total_size = 0;
	while (read_size != 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		printf("%s\n", buf);
		if (read_size == 0)
			break ;
		total_size += read_size;
		line = ft_realloc(line, total_size);
		buf_idx = 0;
		while (*(buf + buf_idx) != '\n' && buf_idx < BUFFER_SIZE)
			line[line_idx++] = buf[buf_idx++];
		line[line_idx] == '\0';
		if (*(buf + buf_idx) == '\n')
		{
			line[line_idx] == '\n';
			free(buf);
			return (line);
		}
	}
	return (NULL);
}
