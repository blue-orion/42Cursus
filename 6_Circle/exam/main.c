#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>

typedef struct s_client {
	int	id;
	int	client_fd;
}	t_client;

t_client	client[1024];
int			client_num = 0;

int	main(int ac, char **av) {
	int	max_fd = 1024;
	int sockfd;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in	servaddr;
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(av[1]));

	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
		return 1;
	printf("success to binding\n");
	
	if (listen(sockfd, 10))
		return 1;
	printf("is listening...\n");

	fd_set	read, conn;
	struct timeval	nulltime;
	nulltime.tv_sec = 0;
	nulltime.tv_usec = 0;

	FD_ZERO(&conn);
	FD_ZERO(&read);
	FD_SET(sockfd, &read);

	client_num = sockfd;
	while (1) {
		int	event = select(client_num + 1, &read, NULL, NULL, NULL);
		printf("select return : %d\n", event);
		for (int i = 0; i < client_num + 1; i++) {
			if (!FD_ISSET(i, &read))
				continue ;
			if (i == sockfd) {
				int	fd = accept(sockfd, NULL, NULL);

				if (fd < 0) {
					printf("error to accept\n");
				}
				else
					printf("success to accept\n");
				FD_SET(fd, &read);
				client[i].id = client_num++;
				client[i].client_fd = fd;
			}
			else {
				char	buf[1024] = {0, };
				if (recv(i, buf, 1024, 0) <= 0) {
					FD_CLR(i, &read);
					client_num--;
					printf("Disconnected %d\n", i);
					continue ;
				}
				printf("recv: %s\n", buf);
			}
			FD_SET(sockfd, &read);
		}
	}
}
