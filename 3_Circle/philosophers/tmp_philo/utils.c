/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:21:00 by takwak            #+#    #+#             */
/*   Updated: 2025/03/17 16:27:24 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int time)
{
	struct timeval	start;
	struct timeval	cur;
	int				runtime;

	gettimeofday(&start, NULL);
	while (1)
	{
		gettimeofday(&cur, NULL);
		runtime = (cur.tv_sec - start.tv_sec) * 1000
			+ (cur.tv_usec - start.tv_usec) / 1000;
		if (runtime >= time)
			break ;
		usleep(30);
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
	while (get_value(&info->common->print))
		usleep(20);
	set_value(&info->common->print, 1);
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
	set_value(&info->common->print, 0);
}
