/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:06:32 by takwak            #+#    #+#             */
/*   Updated: 2025/03/20 13:03:16 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_stop(t_philo *philo);

void	philo_fork(t_philo *philo)
{
	while (!philo_stop(philo) && !get_value(&philo->common->fork[philo->left]))
		usleep(20);
	if (philo_stop(philo))
		return ;
	set_value(&philo->common->fork[philo->left], 0);
	print_log(philo, get_runtime(philo->info->start_time), FORK);
	while (!philo_stop(philo) && !get_value(&philo->common->fork[philo->right]))
		usleep(20);
	if (philo_stop(philo))
		return ;
	set_value(&philo->common->fork[philo->right], 0);
	print_log(philo, get_runtime(philo->info->start_time), FORK);
}

void	philo_eat(t_philo *philo)
{
	if (philo_stop(philo))
		return ;
	print_log(philo, get_runtime(philo->info->start_time), EAT);
	gettimeofday(&philo->last_eat_time, NULL);
	ft_usleep(philo, philo->info->time_to_eat);
	set_value(&philo->common->fork[philo->left], 1);
	set_value(&philo->common->fork[philo->right], 1);
	philo->eat_cnt++;
	if (philo->eat_cnt == philo->info->must_eat_cnt)
		set_value(&philo->stop, EAT);
}

void	philo_sleep(t_philo *philo)
{
	if (philo_stop(philo))
		return ;
	print_log(philo, get_runtime(philo->info->start_time), SLEEP);
	ft_usleep(philo, philo->info->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	if (philo_stop(philo))
		return ;
	print_log(philo, get_runtime(philo->info->start_time), THINK);
}

int	philo_stop(t_philo *philo)
{
	if (get_value(&philo->common->stop) || get_value(&philo->stop) == DIE)
		return (1);
	if (get_runtime(philo->last_eat_time) >= philo->info->time_to_die)
	{
		print_log(philo, get_runtime(philo->info->start_time), DIE);
		set_value(&philo->stop, DIE);
		return (1);
	}
	return (0);
}
