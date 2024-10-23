#include "../get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
	char	*res;

	// File input
	fd = open("text.txt", O_RDONLY);
	for (int i = 1;; i++)
	{
		res = get_next_line(fd);
		if (res == NULL)
			break ;
		printf("call count : %d || ", i);
		printf("%s\n", res);
	}
	close(fd);

	// Standard input
	// fd = 0;
	// while (printf("%s", get_next_line(fd)) != 0)	;
	// printf("%s", get_next_line(fd));

}
