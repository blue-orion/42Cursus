#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	char	command[100];

	if (argc > 2)
	{
		printf("Invalid argc");
		return (0);
	}
	if (argc == 1)
	{
		strcpy(command, "cc ");
		strcat(command, " ../get_next_line.c ../get_next_line_utils.c test.c -o test.out");

	}
	else
	{
		strcpy(command, "cc ");
		// strcat(command, "-Wall -Wextra -Werror ");
		strcat(command, "-D BUFFER_SIZE=");
		strcat(command, argv[1]);
		strcat(command, " ../get_next_line.c ../get_next_line_utils.c test.c ");
		strcat(command, "-o test.out");
	}
	printf("%s\n", command);
	int	ret = system(command);
	
	if (ret != 0)
		printf("ret : %d \n", ret);
	// test.out 실행
	if (ret == 0)
	{
		printf("./test.out\n");
		printf("===============================================================================\n\n");
		ret = system("./test.out");
		printf("===============================================================================\n");
	}
	if (ret == 0)
	{
		printf("rm test.out\n");
		ret = system("rm test.out");
	}
	return (0);
}
