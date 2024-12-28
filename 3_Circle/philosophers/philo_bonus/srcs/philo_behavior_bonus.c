/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:39:13 by takwak            #+#    #+#             */
/*   Updated: 2024/12/29 01:37:16 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	philo_eat(t_philo *philo)
{
	int	runtime;

	if (check_dead(philo))
		return (0);
	pthread_mutex_unlock(philo->flag_mutex);
	pthread_mutex_lock(philo->time_mutex);
	philo->status = EAT;
	gettimeofday(&philo->cur_time, NULL);
	runtime = get_runtime(philo->cur_time, philo->common->start_time);
	print_log(philo, runtime);
	gettimeofday(&philo->last_eat_time, NULL);
	pthread_mutex_unlock(philo->time_mutex);
	usleep(philo->info->time_to_eat * 1000);
	sem_post(philo->common->fork_sem);
	sem_post(philo->common->fork_sem);
	philo->having_fork_num -= 2;
	philo->eat_cnt += 1;
	return (0);
}

int	philo_think(t_philo *philo)
{
	int	runtime;

	if (check_dead(philo))
		return (0);
	pthread_mutex_lock(philo->time_mutex);
	philo->status = THINK;
	gettimeofday(&philo->cur_time, NULL);
	runtime = get_runtime(philo->cur_time, philo->common->start_time);
	print_log(philo, runtime);
	pthread_mutex_unlock(philo->time_mutex);
	usleep(1000);
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	int	runtime;

	if (check_dead(philo))
		return (0);
	pthread_mutex_lock(philo->time_mutex);
	philo->status = SLEEP;
	gettimeofday(&philo->cur_time, NULL);
	runtime = get_runtime(philo->cur_time, philo->common->start_time);
	print_log(philo, runtime);
	pthread_mutex_unlock(philo->time_mutex);
	usleep(philo->info->time_to_sleep * 1000);
	return (0);
}

int	philo_take_fork(t_philo *philo)
{
	int	runtime;

	if (check_dead(philo))
		return (0);
	pthread_mutex_lock(philo->time_mutex);
	sem_wait(philo->common->fork_sem);
	philo->having_fork_num += 1;
	philo->status = FORK;
	gettimeofday(&philo->cur_time, NULL);
	runtime = get_runtime(philo->cur_time, philo->common->start_time);
	pthread_mutex_unlock(philo->time_mutex);
	print_log(philo, runtime);
	return (0);
}
