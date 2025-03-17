/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 04:15:39 by takwak            #+#    #+#             */
/*   Updated: 2025/03/17 18:37:22 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_iam_end(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	sem_wait(philo->flag_sem->adr);
	if (philo->flag == FINISH)
	{
		philo->status = FINISH;
		sem_post(philo->flag_sem->adr);
		return (1);
	}
	if (philo->flag == DIE)
	{
		philo->status = DIE;
		sem_post(philo->flag_sem->adr);
		return (1);
	}
	sem_post(philo->flag_sem->adr);
	return (0);
}

int	end_process(t_philo *philo)
{
	int	end_status;

	end_status = philo->status;
	sem_close(philo->common->print_sem->adr);
	sem_close(philo->common->fork_sem->adr);
	free(philo->common->fork_sem);
	free(philo->common->print_sem);
	free_philo_resource(philo);
	free(philo->info->pid);
	free(philo);
	exit(end_status);
}
