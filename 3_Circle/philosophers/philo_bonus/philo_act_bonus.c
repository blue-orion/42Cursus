/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:36:52 by takwak            #+#    #+#             */
/*   Updated: 2025/03/19 16:44:55 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	have_to_stop(t_philo *philo)
{
	int	runtime;

	if (philo->eat_cnt >= philo->info->must_eat_cnt)
		return (EAT);
	if (philo->died)
		return (DIE);
	runtime = get_runtime(philo->last_eat_time);
	if (runtime >= philo->info->time_to_die)
	{
		philo->died = 1;
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
	ft_usleep(philo, philo->info->time_to_eat);
	philo->eat_cnt++;
	sem_post(philo->common->fork);
	sem_post(philo->common->fork);
}

void	philo_sleep(t_philo *philo)
{
	if (have_to_stop(philo))
		return ;
	print_log(philo, get_runtime(philo->info->start_time), SLEEP);
	ft_usleep(philo, philo->info->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	if (have_to_stop(philo))
		return ;
	print_log(philo, get_runtime(philo->info->start_time), THINK);
	ft_usleep(philo, 100);
}
