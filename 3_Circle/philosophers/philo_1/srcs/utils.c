/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:33:26 by takwak            #+#    #+#             */
/*   Updated: 2024/12/23 01:38:15 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	end_process(t_info *info, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_join(philos[i].tid, NULL);
		i++;
	}
	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_mutex_destroy(&info->fork_mutex[i]);
		i++;
	}
	free(info->fork_mutex);
	pthread_mutex_destroy(&info->print_mutex);
	free(info->fork);
	free(info);
	free(philos);
	exit(EXIT_SUCCESS);
}

void	free_info(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_mutex_destroy(&info->fork_mutex[i]);
		i++;
	}
	free(info->fork_mutex);
	pthread_mutex_destroy(&info->print_mutex);
	free(info->fork);
	free(info);
}

void	error_in_fork_making(t_info *info, int success_num)
{
	int	i;

	perror("Error in mutex_init");
	i = 0;
	while (i < success_num)
	{
		pthread_mutex_destroy(&info->fork_mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&info->print_mutex);
	free(info->fork_mutex);
	free(info->fork);
	free(info);
	exit(EXIT_FAILURE);
}

void	error_in_print_mutex_making(t_info *info)
{
	perror("Error in mutex_init");
	free(info);
	exit(EXIT_FAILURE);
}

void	error_in_make_threads(t_info *info, t_philo *philo, int success_num)
{
	int	i;

	perror("Error in makeing threads");
	free_info(info);
	if (philo)
	{
		pthread_mutex_lock(&info->end_flag_mutex);
		info->end_flag = 1;
		pthread_mutex_unlock(&info->end_flag_mutex);
		i = 0;
		while (i < success_num)
		{
			pthread_join(philo[i].tid, NULL);
			i++;
		}
	}
	exit(EXIT_FAILURE);
}
