/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 03:30:04 by takwak            #+#    #+#             */
/*   Updated: 2024/12/29 04:21:21 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	make_mutex(t_mutex *mutex, t_philo *philo)
{
	if (pthread_mutex_init(&philo->mutex->eat_cnt_mutex, NULL))
		return (-1);
	if (pthread_mutex_init(&philo->mutex->status_mutex, NULL))
	{
		pthread_mutex_destroy(&philo->mutex->eat_cnt_mutex);
		return (-1);
	}
	if (pthread_mutex_init(&philo->mutex->time_mutex, NULL))
	{
		pthread_mutex_destroy(&philo->mutex->eat_cnt_mutex);
		pthread_mutex_destroy(&philo->mutex->status_mutex);
		return (-1);
	}
	philo->mutex = mutex;
	if (pthread_create(&philo->tid, NULL, monitoring, (void *)philo))
	{
		pthread_mutex_destroy(&philo->mutex->eat_cnt_mutex);
		pthread_mutex_destroy(&philo->mutex->status_mutex);
		pthread_mutex_destroy(&philo->mutex->time_mutex);
		return (-1);
	}
	return (0);
}

void	philo_main(t_philo *philo)
{
	t_mutex	mutex;

	memset(&mutex, 0, sizeof(t_mutex));
	if (make_mutex(&mutex, philo))
	{
		perror("Error in making mutex");
		exit(EXIT_FAILURE);
	}
	start_behavior(philo);
	exit(philo->status);
}
