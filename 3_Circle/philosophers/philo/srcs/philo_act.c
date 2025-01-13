/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:01:56 by takwak            #+#    #+#             */
/*   Updated: 2025/01/13 18:19:03 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	philo_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->fork[philo->id]);
	philo->status = FORK;
	philo->runtime = get_runtime(philo, philo->start_time);
	pthread_mutex_unlock(&philo->common->fork[philo->id]);
	if (print_log(philo, philo->runtime))
		return (-1);
}

int	philo_eat(t_philo *philo)
{
	
}

int	philo_sleep(t_philo *philo)
{

}

int	philo_think(t_philo *philo)
{

}

int	philo_die(t_philo *philo)
{

}
