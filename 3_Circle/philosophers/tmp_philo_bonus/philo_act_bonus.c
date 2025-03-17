/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:36:52 by takwak            #+#    #+#             */
/*   Updated: 2025/03/17 21:23:30 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	have_to_stop(t_philo *philo)
{
	int	runtime;

	if (get_value(&philo->common->end))
		return (1);
	if (get_value(&philo->stop) == DIE)
		return (1);
	runtime = get_runtime(philo->last_eat_time);
	if (runtime >= philo->info->time_to_die)
	{
		set_value(&philo->stop, DIE);
		print_log(philo, get_runtime(philo->info->start_time), DIE);
		return (1);
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
		set_value(&philo->stop, EAT);
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
