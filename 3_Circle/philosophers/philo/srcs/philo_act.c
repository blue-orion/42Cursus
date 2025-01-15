/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:01:56 by takwak            #+#    #+#             */
/*   Updated: 2025/01/15 15:51:26 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	philo_fork(t_philo *philo)
{
	int	runtime;

	if (is_stop(philo))
		return (-1);
	pthread_mutex_lock(&philo->common->fork[philo->left]);
	philo->status = FORK;
	runtime = get_runtime(philo->start_time);
	if (print_log(philo, runtime))
		return (-1);
	philo_think(philo);
	if (is_stop(philo) || philo->info->num_of_philo == 1)
		return (-1);
	pthread_mutex_lock(&philo->common->fork[philo->right]);
	philo->status = FORK;
	runtime = get_runtime(philo->start_time);
	if (print_log(philo, runtime))
		return (-1);
	return (0);
}

int	philo_eat(t_philo *philo)
{
	int	runtime;

	if (is_stop(philo))
		return (-1);
	philo->status = EAT;
	runtime = get_runtime(philo->start_time);
	gettimeofday(&philo->last_eat_time, NULL);
	if (print_log(philo, runtime))
		return (-1);
	usleep(philo->info->time_to_eat * 1000);
	philo->eat_cnt++;
	if (is_stop(philo))
		return (-1);
	pthread_mutex_unlock(&philo->common->fork[philo->left]);
	pthread_mutex_unlock(&philo->common->fork[philo->right]);
	if (philo->eat_cnt == philo->info->must_eat)
		philo->status = FINISH;
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	int	runtime;

	if (is_stop(philo))
		return (-1);
	philo->status = SLEEP;
	runtime = get_runtime(philo->start_time);
	if (print_log(philo, runtime))
		return (-1);
	usleep(philo->info->time_to_sleep * 1000);
	return (0);
}

int	philo_think(t_philo *philo)
{
	int	runtime;

	if (is_stop(philo))
		return (-1);
	philo->status = THINK;
	runtime = get_runtime(philo->start_time);
	if (print_log(philo, runtime))
		return (-1);
	return (0);
}
