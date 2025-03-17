/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:44:04 by takwak            #+#    #+#             */
/*   Updated: 2025/03/17 17:15:40 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	get_runtime(t_philo *philo, struct timeval start_time)
{
	int	runtime;
	int	sec;
	int	usec;

	sem_wait(philo->time_sem->adr);
	gettimeofday(&philo->cur_time, NULL);
	sec = philo->cur_time.tv_sec - start_time.tv_sec;
	usec = philo->cur_time.tv_usec - start_time.tv_usec;
	runtime = sec * 1000 + usec / 1000;
	sem_post(philo->time_sem->adr);
	return (runtime);
}
