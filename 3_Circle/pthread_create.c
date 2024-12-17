/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 00:06:01 by takwak            #+#    #+#             */
/*   Updated: 2024/12/17 03:57:18 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	*thread_main(void *param)
{
	int	cnt;
	char	a[1000000];

	cnt = *(int *)param;
	for (int i = 0; i < cnt; i++)
	{
		usleep(1000000);
		printf("running thread\n");
	}
	return ((void *)"Thread Killed\n");
}

void *thread_func(void *arg) {
    // int a[100000]; // 스택 메모리 사용
    // for (int i = 0; i < 100000; i++) {
    //     a[i] = i;
    // }

    int *b = malloc(100000 * sizeof(int)); // 힙 메모리 사용
    if (b == NULL) {
        perror("malloc");
        return NULL;
    }
    for (int i = 0; i < 100000; i++) {
        b[i] = i;
    }

    printf("Thread: allocated memory and finished\n");
    // malloc 메모리 해제하지 않음 (메모리 누수 실험)
    free(b); // 힙 메모리 해제하려면 이 부분 활성화
	usleep(3000000);
    return NULL;
}

int	main(void)
{
	pthread_t	t_id;
	int	thread_param = 5;
	void	*status;

	usleep(4000000);
	if (pthread_create(&t_id, NULL, thread_func, (void *)&thread_param) != 0)
		perror("pthread_create error");
	pthread_detach(t_id);
	printf("%d\n", pthread_join(t_id, &status));
	perror("join");
	printf("end of main\n");
	usleep(10000000);
	// printf("%s", (char *)status);
	return (0);
}
