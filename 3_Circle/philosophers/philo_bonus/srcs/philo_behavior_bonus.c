/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 04:21:45 by takwak            #+#    #+#             */
/*   Updated: 2024/12/29 20:20:23 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>
#include <sys/time.h>

int	philo_take_fork(t_philo *philo)
{
	int	runtime;

	if (is_iam_end(philo))
		return (1);
	sem_wait(philo->common->fork_sem->adr);
	philo->status = FORK;
	runtime = get_runtime(philo, philo->info->start_time);
	print_log(runtime, philo);
	sem_wait(philo->common->fork_sem->adr);
	philo->status = FORK;
	runtime = get_runtime(philo, philo->info->start_time);
	print_log(runtime, philo);
	return (0);
}

int	philo_eat(t_philo *philo)
{
	int	runtime;
	
	if (is_iam_end(philo))
		return (1);
	philo->status = EAT;
	runtime = get_runtime(philo, philo->info->start_time);
	gettimeofday(&philo->last_eat_time, NULL);
	print_log(runtime, philo);
	usleep(philo->info->time_to_eat * 1000);
	sem_wait(philo->eat_cnt_sem->adr);
	philo->eat_cnt += 1;
	sem_post(philo->eat_cnt_sem->adr);
	sem_post(philo->common->fork_sem->adr);
	sem_post(philo->common->fork_sem->adr);
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	int	runtime;

	if (is_iam_end(philo) || is_philo_eat_finish(philo))
		return (1);
	philo->status = SLEEP;
	runtime = get_runtime(philo, philo->info->start_time);
	print_log(runtime, philo);
	usleep(philo->info->time_to_sleep * 1000);
	return (0);
}

int	philo_think(t_philo *philo)
{
	int	runtime;

	if (is_iam_end(philo))
		return (1);
	philo->status = THINK;
	runtime = get_runtime(philo, philo->info->start_time);
	print_log(runtime, philo);
	usleep(10000);
	return (0);
}
