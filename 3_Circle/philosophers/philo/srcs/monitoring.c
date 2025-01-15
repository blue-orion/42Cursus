/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:50:40 by takwak            #+#    #+#             */
/*   Updated: 2025/01/15 16:38:00 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->die);
	if (philo->common->dead_flag)
	{
		pthread_mutex_unlock(&philo->common->die);
		return (1);
	}
	pthread_mutex_unlock(&philo->common->die);
	return (0);
}

int	check_dead(t_philo *philo)
{
	int	runtime;

	runtime = get_runtime(philo->last_eat_time);
	if (runtime > philo->info->time_to_die)
	{
		pthread_mutex_lock(&philo->common->die);
		philo->common->dead_flag = 1;
		runtime = get_runtime(philo->start_time);
		pthread_mutex_unlock(&philo->common->die);
		pthread_mutex_lock(&philo->common->log);
		printf("%d %d is died\n", runtime, philo->id);
		pthread_mutex_unlock(&philo->common->log);
		return (1);
	}
	return (0);
}

void	monitoring(t_philo *philo)
{
	int	finish_cnt;
	int	i;

	finish_cnt = 0;
	while (1)
	{
		usleep(500);
		if (is_dead(philo) || finish_cnt == philo->info->num_of_philo)
			break ;
		i = 0;
		while (i < philo->info->num_of_philo)
		{
			if (check_dead(&philo[i]))
				break ;
			if (philo[i].status == FINISH)
			{
				finish_cnt++;
				pthread_join(philo[i].tid, NULL);
				philo[i].status = EXIT;
			}
			i++;
		}
	}
}
