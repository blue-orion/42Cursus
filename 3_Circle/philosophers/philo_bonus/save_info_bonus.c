/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_info_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:30:00 by takwak            #+#    #+#             */
/*   Updated: 2025/03/17 18:30:12 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	save_info(t_info *info, int argc, char **argv)
{
	info->num_of_philo = ft_philo_atoi(argv[1]);
	info->time_to_die = ft_philo_atoi(argv[2]);
	info->time_to_eat = ft_philo_atoi(argv[3]);
	info->time_to_sleep = ft_philo_atoi(argv[4]);
	if (info->num_of_philo <= 0 || info->time_to_die <= 0
		|| info->time_to_eat <= 0 || info->time_to_sleep <= 0)
		return (1);
	if (argc == 6)
	{
		info->must_eat_time = ft_philo_atoi(argv[5]);
		if (info->must_eat_time <= 0)
			return (1);
	}
	else
		info->must_eat_time = -1;
	gettimeofday(&info->start_time, NULL);
	info->pid = (pid_t *)malloc(sizeof(pid_t) * info->num_of_philo);
	if (!info->pid)
		return (1);
	return (0);
}

