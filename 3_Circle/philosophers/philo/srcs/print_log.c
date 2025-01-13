/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:12:35 by takwak            #+#    #+#             */
/*   Updated: 2025/01/13 17:05:49 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	print_log(t_philo *philo, int runtime)
{
	pthread_mutex_lock(&philo->common->log);
	printf("%d ", runtime);
	if (philo->status == DIE)
	{
		printf("%d is died\n", philo->id);
		return (0);
	}
	if (philo->status == FORK)
		printf("%d has taken a fork\n", philo->id);
	if (philo->status == EAT)
		printf("%d is eating\n", philo->id);
	if (philo->status == SLEEP)
		printf("%d is sleeping\n", philo->id);
	if (philo->status == THINK)
		printf("%d is thinking\n", philo->id);
	pthread_mutex_unlock(&philo->common->log);
	return (0);
}
