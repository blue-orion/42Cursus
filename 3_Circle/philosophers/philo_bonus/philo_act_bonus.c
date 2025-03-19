/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:36:52 by takwak            #+#    #+#             */
/*   Updated: 2025/03/19 20:57:03 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	have_to_stop(t_philo *philo)
{
	if (philo->eat_cnt >= philo->info->must_eat_cnt)
	{
		sem_wait(philo->die);
		philo->die_value = EAT;
		sem_post(philo->die);
		return (EAT);
	}
	sem_wait(philo->die);
	if (philo->die_value == DIE)
	{
		sem_post(philo->die);
		return (DIE);
	}
	sem_post(philo->die);
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
	sem_wait(philo->die);
	gettimeofday(&philo->last_eat_time, NULL);
	sem_post(philo->die);
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
	usleep(100);
}
