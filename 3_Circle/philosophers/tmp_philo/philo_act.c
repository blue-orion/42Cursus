/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:06:32 by takwak            #+#    #+#             */
/*   Updated: 2025/03/13 22:23:29 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_fork(t_philo *philo)
{
	if (get_value(&philo->die))
		return ;
	while (get_value(&philo->common->fork[philo->left]))
		usleep(20);
	set_value(&philo->common->fork[philo->left], 0);
	print_log(philo, get_time() - philo->info->start_time, FORK);
	if (get_value(&philo->die))
		return ;
	while (get_value(&philo->common->fork[philo->right]))
		usleep(20);
	set_value(&philo->common->fork[philo->right], 0);
	print_log(philo, get_time() - philo->info->start_time, FORK);
}

int	philo_die(t_philo *philo)
{
	if (get_time() - philo->last_eat_time >= philo->info->time_of_die)
	{
		print_log(philo, get_time() - philo->info->start_time, DIE);
		set_value(&philo->die, 1);
		return (1);
	}
	return (0);
}
