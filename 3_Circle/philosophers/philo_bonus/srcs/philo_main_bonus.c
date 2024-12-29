/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 03:30:04 by takwak            #+#    #+#             */
/*   Updated: 2024/12/29 20:02:55 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	philo_main(t_philo *philo)
{
	pthread_create(&philo->tid, NULL, monitoring, (void *)philo);
	if (philo->id % 2 == 0)
		philo_think(philo);
	while (1)
	{
		philo_take_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		if (is_iam_end(philo))
			break ;
	}
	exit(philo->status);
}
