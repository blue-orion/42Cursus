/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:58:23 by takwak            #+#    #+#             */
/*   Updated: 2025/03/19 16:41:47 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitoring_thread(void *data);
void	*check_die_thread(void *data);

void	monitoring(t_philo *philo)
{
	int	status;
	int	finish;
	int	i;

	finish = 0;
	while (1)
	{
		waitpid(-1, &status, 0);
		if (status >> 8 == DIE)
		{
			i = 0;
			while (i < philo->info->num_of_philo)
				kill(philo[i++].pid, SIGKILL);
			break ;
		}
		if (status >> 8 == EAT)
			finish++;
		if (finish == philo->info->num_of_philo)
			break ;
		ft_usleep(philo, 200);
	}
}
