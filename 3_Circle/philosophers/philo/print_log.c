/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:12:35 by takwak            #+#    #+#             */
/*   Updated: 2025/03/11 22:07:26 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_log(t_philo *philo, int runtime)
{
	pthread_mutex_lock(&philo->common->log);
	if (is_stop(philo))
	{
		pthread_mutex_unlock(&philo->common->log);
		return (-1);
	}
	if (philo->status == FORK)
		printf("%d %d has taken a fork\n", runtime, philo->id);
	if (philo->status == EAT)
		printf("%d %d is eating\n", runtime, philo->id);
	if (philo->status == SLEEP)
		printf("%d %d is sleeping\n", runtime, philo->id);
	if (philo->status == THINK)
		printf("%d %d is thinking\n", runtime, philo->id);
	pthread_mutex_unlock(&philo->common->log);
	return (0);
}
