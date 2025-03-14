/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:19:07 by takwak            #+#    #+#             */
/*   Updated: 2025/03/14 18:18:27 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	save_info(t_info *info, int ac, char **av)
{
	info->num_of_philo = ft_philo_atoi(av[1]);
	info->time_to_die = ft_philo_atoi(av[2]) * 1000;
	info->time_to_eat = ft_philo_atoi(av[3]) * 1000;
	info->time_to_sleep = ft_philo_atoi(av[4]) * 1000;
	if (ac == 6)
		info->must_eat_cnt = ft_philo_atoi(av[5]);
	else
		info->must_eat_cnt = -1;
	if (info->num_of_philo < 1 || info->time_to_die < 1
		|| info->time_to_eat < 1 || info->time_to_sleep < 1
		|| (ac == 6 && info->must_eat_cnt < 1))
		return (1);
	gettimeofday(&info->start_time, NULL);
	return (0);
}
