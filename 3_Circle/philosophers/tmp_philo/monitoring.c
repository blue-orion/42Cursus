/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:48:48 by takwak            #+#    #+#             */
/*   Updated: 2025/03/16 21:11:22 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitoring(t_philo *philo)
{
	int	i;
	int	finish;
	int	status;
	int	*eat_finish;

	finish = 0;
	eat_finish = (int *)malloc(sizeof(int) * philo->info->num_of_philo);
	i = 0;
	while (i < philo->info->num_of_philo)
	{
		eat_finish[i] = 0;
		i++;
	}
	while (1)
	{
		if (status == DIE)
			break ;
		i = 0;
		finish = 0;
		while (i < philo->info->num_of_philo)
		{
			if (eat_finish[i] == 1)
				finish++;
			i++;
		}
		if (finish == philo->info->num_of_philo)
			break ;
		i = 0;
		while (i < philo->info->num_of_philo)
		{
			status = get_value(&philo[i].stop);
			if (status == EAT)
				eat_finish[i] = 1;
			if (status == DIE)
				break ;
			i++;
		}
		usleep(1000);
	}
	free(eat_finish);
	set_value(&philo->common->stop, 1);
}
