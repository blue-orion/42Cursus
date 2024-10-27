#include "../get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
	int		fd2;
	char	*res;

	// File input
	fd = open("text.txt", O_RDONLY);
	fd2 = open("text_user.txt", O_WRONLY | O_CREAT | O_TRUNC);
	printf("fd == %d\n", fd);
	for (int i = 1;; i++)
	{
		res = get_next_line(fd);
		if (res == NULL)
			break ;
		printf("call count : %d || ", i);
		printf("%s", res);
		write(fd2, res, strlen(res));
		free(res);
	}
	close(fd);
	close(fd2);

	// Standard input
	// fd = 0;
	// while (printf("%s", get_next_line(fd)) != 0)	;
	// printf("%s", get_next_line(fd));

}
