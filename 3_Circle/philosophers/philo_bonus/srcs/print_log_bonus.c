/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:21:08 by takwak            #+#    #+#             */
/*   Updated: 2024/12/28 22:40:39 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	print_log(t_philo *philo, int runtime)
{
	if (philo->flag)
		return (-1);
	sem_wait(philo->common->print_sem);
	printf("%d ", runtime);
	if (philo->status == FORK)
		printf("%d has taken a fork\n", philo->id);
	if (philo->status == EAT)
		printf("%d is eating\n", philo->id);
	if (philo->status == SLEEP)
		printf("%d is sleeping\n", philo->id);
	if (philo->status == THINK)
		printf("%d is thinking\n", philo->id);
	if (philo->status == DIE)
	{
		printf("%d is died\n", philo->id);
		return (0);
	}
	sem_post(philo->common->print_sem);
	return (0);
}
