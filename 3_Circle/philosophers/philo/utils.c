/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:21:00 by takwak            #+#    #+#             */
/*   Updated: 2025/03/19 19:03:43 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(t_philo *philo, int time)
{
	int				start_run;
	struct timeval	start;
	int				runtime;

	start_run = get_runtime(philo->info->start_time);
	gettimeofday(&start, NULL);
	runtime = get_runtime(philo->info->start_time);
	while (runtime - start_run < time)
	{
		if (runtime - start_run >= philo->info->time_to_die)
			break ;
		usleep(30);
		runtime = get_runtime(philo->info->start_time);
	}
}

int	get_runtime(struct timeval start)
{
	struct timeval	tv;
	int				runtime;
	int				sec;
	int				usec;

	gettimeofday(&tv, NULL);
	sec = tv.tv_sec - start.tv_sec;
	usec = tv.tv_usec - start.tv_usec;
	runtime = sec * 1000 + usec / 1000;
	return (runtime);
}

void	print_log(t_philo *info, int time, int status)
{
	pthread_mutex_lock(&info->common->print.lock);
	if (get_value(&info->common->stop))
	{
		pthread_mutex_unlock(&info->common->print.lock);
		return ;
	}
	if (status == FORK)
		printf("%d %d has taken a fork\n", time, info->id);
	if (status == EAT)
		printf("%d %d is eating\n", time, info->id);
	if (status == SLEEP)
		printf("%d %d is sleeping\n", time, info->id);
	if (status == THINK)
		printf("%d %d is thinking\n", time, info->id);
	if (status == DIE)
		printf("%d %d is died\n", time, info->id);
	pthread_mutex_unlock(&info->common->print.lock);
}
