#include "get_next_line.h"
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd)
{
	char	*buf;
	int		buf_idx;
	char	*line;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	// while (read(fd, buf, BUFFER_SIZE) != 0)
	// {
	// 	buf_idx = 0;
	// 	strcpy(line, buf);
	// 	while (*(buf + buf_idx) != '\n' || *(buf + buf_idx))
	// 	{
	// 	}
	// }
	if (read(fd, buf, BUFFER_SIZE) == 0)
		buf = NULL;
	return (buf);
}
