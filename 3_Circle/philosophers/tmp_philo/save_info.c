/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:19:07 by takwak            #+#    #+#             */
/*   Updated: 2025/03/13 21:57:09 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	save_info(t_info *info, int ac, char **av)
{
	struct timeval	tv;

	info->num_of_philo = ft_philo_atoi(av[1]);
	info->time_of_die = ft_philo_atoi(av[2]);
	info->time_of_eat = ft_philo_atoi(av[3]);
	info->time_of_sleep = ft_philo_atoi(av[4]);
	if (ac == 6)
		info->must_eat_cnt = ft_philo_atoi(av[5]);
	else
		info->must_eat_cnt = -1;
	if (info->num_of_philo < 1 || info->time_of_die < 1
		|| info->time_of_eat < 1 || info->time_of_sleep < 1
		|| (ac == 6 && info->must_eat_cnt < 1))
		return (1);
	gettimeofday(&tv, NULL);
	info->start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (0);
}
