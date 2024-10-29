#include "../get_next_line_bonus.h"
#include "../get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd);

int	main(void)
{
	int		cur_fd;
	int		cur_fd_user;
	int		fd;
	int		fd_user;
	int		fd2;
	int		fd2_user;
	int		fd3;
	int		fd3_user;
	char	*res;
	int		cnt;

	printf("Invalid fd\n");
	res = get_next_line(-1);
	printf("res : %s\n", res);
	// File input
	if ((fd = open("text.txt", O_RDONLY)) == -1)
		return (printf("file open failed\n"));
	if ((fd_user = open("text_user.txt", O_WRONLY | O_CREAT | O_TRUNC)) == -1)
		return (printf("file open failed\n"));
	if ((fd2 = open("41_no_nl.txt", O_RDONLY)) == -1)
		return (printf("file open failed\n"));
	if ((fd2_user = open("41_no_nl_user.txt", O_WRONLY | O_CREAT | O_TRUNC)) == -1)
		return (printf("file open failed\n"));
	if ((fd3 = open("read_error.txt", O_RDONLY)) == -1)
		return (printf("file open failed\n"));
	if ((fd3_user = open("read_error_user.txt", O_WRONLY | O_CREAT | O_TRUNC)) == -1)
		return (printf("file open failed\n"));
	cnt = 1;
	int	fd_flag = 0;
	int	fd2_flag = 0;
	int	fd3_flag = 0;
	while (1)
	{
		if (fd_flag && fd2_flag && fd3_flag)
			break ;
		for (int i = 3; i <= 7; i += 2)
		{
			cur_fd = i;
			cur_fd_user = i + 1;
			if (cur_fd == 3 && fd_flag == 1)
				continue ;
			if (cur_fd == 5 && fd2_flag == 1)
				continue ;
			if (cur_fd == 7 && fd3_flag == 1)
				continue ;
			res = get_next_line(cur_fd);
			if (res == NULL)
			{
				if (cur_fd == 3)
					fd_flag = 1;
				if (cur_fd == 5)
					fd2_flag = 1;
				if (cur_fd == 7)
					fd3_flag = 1;
				continue ;
			}
			printf("\nfd = %d\ncall count : %d || ", cur_fd, cnt++);
			printf("%s", res);
			write(cur_fd_user, res, strlen(res));
			free(res);
		}
	}
	close(fd);
	close(fd_user);
	close(fd2);
	close(fd2_user);
	close(fd3);
	close(fd3_user);

	// fd = 0;
	// while (printf("%s", get_next_line(fd)) != 0)	;
	// printf("%s", get_next_line(fd));

}
