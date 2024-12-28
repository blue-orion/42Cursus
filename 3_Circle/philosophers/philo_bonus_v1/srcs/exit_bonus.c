/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:57:12 by takwak            #+#    #+#             */
/*   Updated: 2024/12/29 01:51:29 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	error_exit(void)
{
	perror("Error in setting initial state");
	exit(EXIT_FAILURE);
}

void	success_exit(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->info->num_of_philo)
	{
		pthread_mutex_destroy(philos->time_mutex);
		pthread_mutex_destroy(philos->flag_mutex);
		// free(philos->time_mutex);
		// free(philos->flag_mutex);
		i++;
	}
	free_common(philos->common);
	free(philos->info);
	free(philos);
	exit(EXIT_SUCCESS);
}
