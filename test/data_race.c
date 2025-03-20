#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void	*thread_main(void *data);

int	main(void)
{
	int	a;
	int	b;
	pthread_t	tid;

	pthread_create(&tid, NULL, thread_main, &a);
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			a = 10;
		usleep(10);
	}
	pthread_join(tid, NULL);
}

void	*thread_main(void *data)
{
	int	*a;

	a = (int *)data;
	for (int i = 0; i < 10; i++)
	{
		if (*a == 10)
			printf("a = %d\n", *a);
		else
			printf("data race detected..\n");
		usleep(20);
	}
	return (NULL);
}
