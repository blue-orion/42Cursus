/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:52:57 by takwak            #+#    #+#             */
/*   Updated: 2025/01/13 22:51:45 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	is_stop(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->die);
	if (philo->common->dead_flag)
	{
		pthread_mutex_unlock(&philo->common->die);
		return (1);
	}
	pthread_mutex_unlock(&philo->common->die);
	if (philo->status == FINISH)
		return (1);
	return (0);
}
