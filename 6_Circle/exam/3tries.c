#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct s_client {
	int	id;
	int	fd;
}	t_client;

void	cliadd(t_client *cli, int fd, int id);
void	broadcast(t_client *cli, char *msg, int me);
void	removecli(t_client *cli, int fd);
int	max_fd = 3;
int	client_id = 1;

int	main(int ac, char **av) {
	t_client	cli[1000];
	for (int i = 0; i < 1000; i++) {
		cli[i].id = 0;
		cli[i].fd = -1;
	}
	if (ac != 2) {
		return 0;
	}
	int	socketfd;

	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in	servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(av[1]));

	if (bind(socketfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) {
		perror("error");
		return -1;
	}
	printf("binding success : socket fd = %d\n", socketfd);
	if (listen(socketfd, 10)) {
		perror("error");
		return -1;
	}

	fd_set	conn, read;
	FD_ZERO(&conn);
	FD_SET(socketfd, &conn);

	int	event;
	while (1) {
		read = conn;
		event = select(max_fd + 1, &read, NULL, NULL, NULL);
		for (int i = 3; i < max_fd + 1; i++) {
			if (!FD_ISSET(i, &read)) {
				continue ;
			}
			if (i == socketfd) {
				int	new_client;
				new_client = accept(socketfd, NULL, NULL);

				if (new_client < 0) {
					perror("accept error");
					return -1;
				}
				printf("accept success\n");
				FD_SET(new_client, &conn);
				if (new_client > max_fd)
					max_fd++;
				cliadd(cli, new_client, client_id++);
			}
			else {
				char	buf[1000000];
				int		recved;
				memset(buf, 0, sizeof(buf));
				recved = recv(i, buf, sizeof(buf), 0);
				for (int i = 0; i < recved; i++)
					printf("[%02X]", (unsigned char)buf[i]);
				puts("");
				if (recved == 0) {
					broadcast(cli, "bye bye\n", 0);
					removecli(cli, i);
					FD_CLR(i, &conn);
				}
				if (recved == -1) {
					perror("recv failed");
					return -1;
				}
				broadcast(cli, buf, i);
			}
		}
	}
}

void	cliadd(t_client *cli, int fd, int id) {
	for (int i = 0; i < 1000; i++) {
		if (cli[i].fd == -1) {
			cli[i].fd = fd;
			cli[i].id = id;
			return ;
		}
	}
}

void	removecli(t_client *cli, int fd) {
	for (int i = 0; i < 1000;i ++) {
		if (cli[i].fd == fd) {
			cli[i].fd = -1;
			cli[i].id = 0;
			return ;
		}
	}
}

void	broadcast(t_client *cli, char *msg, int me) {
	for (int i = 0; i < 1000; i++) {
		if (cli[i].fd != -1 && cli[i].fd != me) {
			if (send(cli[i].fd, msg, strlen(msg), 0) == -1) {
				perror("send error");
				exit(1);
			}
		}
	}
}
