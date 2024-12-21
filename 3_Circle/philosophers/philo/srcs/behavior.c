/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:28:14 by takwak            #+#    #+#             */
/*   Updated: 2024/12/22 02:16:51 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	philo_eat(t_philo *philo)
{
	long	time;

	philo->status = EAT;
	time = get_current_time(&philo->cur_time, &philo->info->start_time);
	philo->last_eat_time = philo->cur_time;
	print_log(philo->num, time, EAT, &philo->info->print_mutex);
	philo->eat_num += 1;
	usleep(philo->info->time_to_eat * 1000);
	put_down_left_fork(philo);
	put_down_right_fork(philo);
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	long	time;

	philo->status = SLEEP;
	time = get_current_time(&philo->cur_time, &philo->info->start_time);
	print_log(philo->num, time, SLEEP, &philo->info->print_mutex);
	usleep(philo->info->time_to_sleep * 1000);
	return (0);
}

int	philo_think(t_philo *philo)
{
	long	time;

	if (philo->status == THINK)
		return (0);
	philo->status = THINK;
	time = get_current_time(&philo->cur_time, &philo->info->start_time);
	print_log(philo->num, time, THINK, &philo->info->print_mutex);
	usleep(1000);
	return (0);
}

int	have_to_die(t_philo *philo)
{
	long	time;

	time = get_current_time(&philo->cur_time, &philo->last_eat_time);
	if (time >= philo->info->time_to_die)
	{
		philo->status = DIE;
		time = get_current_time(&philo->cur_time, &philo->info->start_time);
		print_log(philo->num, time, DIE, &philo->info->print_mutex);
		return (1);
	}
	return (0);
}
