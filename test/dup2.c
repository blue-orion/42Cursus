#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

// 0 => 0
// 1 => 1
// 2 => 2
// 3 => 0

int	main(void){
	int newfd;
	int	result;
	newfd = open("dup2.c", O_RDONLY);

	write(3, "write\n", 6);
	printf("%d\n", result);
	perror("error");
	return 0;
}
