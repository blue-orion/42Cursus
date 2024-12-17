#include <sys/time.h>
#include <stdio.h>

#define YEAR 31536000
#define MONTH 2592000
#define DAY 86400
#define HOUR 3600
#define SEC 60

int	main(void)
{
	int		t;
	struct timeval	tv;

	t = gettimeofday(&tv, NULL);
	if (t == -1)
		perror("gettimeofday error");
	printf("t = %ld, tv_sec = %ld, tv_usec = %ld\n", t, tv.tv_sec/31536000 + 1970, tv.tv_usec);


}
