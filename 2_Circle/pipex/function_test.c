#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern char	**environ;

int	main(void)
{
	//test access
	// if (access("test.txt", R_OK) == 0)
	// 	printf("exist and can read file\n");
	// else
	// 	printf("don't exist or cannot read file\n");

	//test execve
	// char	*command;
	// char	**argv;
	//
	// argv = (char **)malloc(sizeof(char *) * 3);
	// command = "ls";
	// argv[0] = command;
	// argv[1] = "-al";
	// argv[2] = NULL;
	//
	// if (execve("/usr/bin/ls", argv, environ) == -1)
	// 	perror("Error: ");
	//
	// //ls 명령어로 binary가 교체되었기 때문에 아래의 코드는 실행되지 않음.
	// printf("ls command\n");
	
	//test fork
	pid_t	pid;
	int		x;

	x = 0;
	pid = fork();
	if (pid > 0)
		printf("Success, parent x = %d, pid = %d\n", --x, pid);
	if (pid == 0)
		printf("I'm child, child x = %d\n", ++x);
	if (pid < 0)
		perror("Error: ");

	//test zombie process
	// if (pid == 0)
	// {
	// 	printf("Chile process exit\n");
	// 	exit(1);
	// }
	// else 
	// {
	// 	sleep(30);
	//  	printf("Parent process exit\n");
	// }
	
	#include <sys/wait.h>
	//test wait
	int	status;

	if (pid > 0)
	{
		pid = wait(&status);
		if (pid == -1)
			perror("Error: ");
		else
		{
			if (WIFEXITED(status)) {
				printf("프로그램에서 exited(%d) 또는 main에서 return %d;하여 종료되었습니다.\n", WEXITSTATUS(status), WEXITSTATUS(status));
			} else if (WIFSIGNALED(status)) {
				printf("signal %d번이 발생하여 종료되었습니다.\n", WTERMSIG(status));
			} else if (WIFSTOPPED(status)) {
				printf("signal %d번으로 인하여 stop되었습니다.\n", WSTOPSIG(status));
			} else if (WIFCONTINUED(status)) {
				printf("STOP된 프로세스를 진행합니다.\n");
			}
		}
	}
	return (1);
}
