/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:25:23 by takwak            #+#    #+#             */
/*   Updated: 2024/12/22 02:17:43 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	print_log(int num, long cur_time, int status, pthread_mutex_t *mutex)
{
	int	err_flag;

	pthread_mutex_lock(mutex);
	err_flag = 0;
	err_flag = printf("%ld ", cur_time);
	if (status == FORK)
		err_flag = printf("%d has taken a fork\n", num);
	if (status == EAT)
		err_flag = printf("%d is eating\n", num);
	if (status == SLEEP)
		err_flag = printf("%d is sleeping\n", num);
	if (status == THINK)
		err_flag = printf("%d is thinking\n", num);
	if (status == DIE)
		err_flag = printf("%d is died\n", num);
	if (err_flag < 0)
		perror("error in print_log");
	pthread_mutex_unlock(mutex);
	return (0);
}
