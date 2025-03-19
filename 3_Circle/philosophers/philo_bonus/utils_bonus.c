/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:21:00 by takwak            #+#    #+#             */
/*   Updated: 2025/03/19 22:06:42 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_usleep(t_philo *philo, int time)
{
	struct timeval	start;
	int				start_run;
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

void	print_log(t_philo *philo, int time, int status)
{
	sem_wait(philo->common->print);
	if (status == FORK)
		printf("%d %d has taken a fork\n", time, philo->id);
	if (status == EAT)
		printf("%d %d is eating\n", time, philo->id);
	if (status == SLEEP)
		printf("%d %d is sleeping\n", time, philo->id);
	if (status == THINK)
		printf("%d %d is thinking\n", time, philo->id);
	if (status == DIE)
		printf("%d %d is died\n", time, philo->id);
	sem_post(philo->common->print);
}

char	*make_sema_name(char *dst, char *src, int num)
{
	int		i;
	int		len;

	len = 0;
	while (src[len])
		len++;
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (num)
	{
		dst[i] = num % 10 + '0';
		i++;
		num /= 10;
	}
	return (dst);
}
