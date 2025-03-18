/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:36:52 by takwak            #+#    #+#             */
/*   Updated: 2025/03/18 21:33:04 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	have_to_stop(t_philo *philo)
{
	int	runtime;

	philo->stop = sem_open("stop", 0);
	if (philo->stop)
	{
		sem_close(philo->stop);
		return (EAT);
	}
	runtime = get_runtime(philo->last_eat_time);
	if (runtime >= philo->info->time_to_die)
	{
		print_log(philo, get_runtime(philo->info->start_time), DIE);
		return (DIE);
	}
	return (0);
}

void	philo_fork(t_philo *philo)
{
	if (have_to_stop(philo))
		return ;
	sem_wait(philo->common->fork);
	print_log(philo, get_runtime(philo->info->start_time), FORK);
	if (have_to_stop(philo))
		return ;
	sem_wait(philo->common->fork);
	print_log(philo, get_runtime(philo->info->start_time), FORK);
}

void	philo_eat(t_philo *philo)
{
	if (have_to_stop(philo))
		return ;
	print_log(philo, get_runtime(philo->info->start_time), EAT);
	gettimeofday(&philo->last_eat_time, NULL);
	ft_usleep(philo->info->time_to_eat);
	philo->eat_cnt++;
	sem_post(philo->common->fork);
	sem_post(philo->common->fork);
	if (philo->eat_cnt == philo->info->must_eat_cnt)
	{
		printf("eat_cnt = %d\n", philo->eat_cnt);
		printf("must_eat_cnt = %d\n", philo->info->must_eat_cnt);
		philo->stop = ft_sem_open(philo->stop_sem_name, 1);
		sem_close(philo->stop);
		printf("%d: seccess make %s sema\n", philo->id, philo->stop_sem_name);
	}
}

void	philo_sleep(t_philo *philo)
{
	if (have_to_stop(philo))
		return ;
	print_log(philo, get_runtime(philo->info->start_time), SLEEP);
	ft_usleep(philo->info->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	if (have_to_stop(philo))
		return ;
	print_log(philo, get_runtime(philo->info->start_time), THINK);
	ft_usleep(100);
}
