/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:39:01 by takwak            #+#    #+#             */
/*   Updated: 2024/12/23 00:53:30 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	init_fork_mutex(t_info *info)
{
	int	i;

	info->fork_mutex = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * info->num_of_philo);
	if (!info->fork_mutex)
		error_in_fork_making(info, 0);
	i = 0;
	while (i < info->num_of_philo)
	{
		if (pthread_mutex_init(&info->fork_mutex[i], NULL))
		{
			error_in_fork_making(info, i);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	make_fork(t_info *info)
{
	info->fork = (int *)malloc(sizeof(int) * info->num_of_philo);
	if (!info->fork)
	{
		pthread_mutex_destroy(&info->print_mutex);
		free(info);
		return (-1);
	}
	memset((void *)info->fork, 0, sizeof(int) * info->num_of_philo);
	return (0);
}

t_info	*save_info(char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		info->have_to_eat = ft_atoi(argv[5]);
	else
		info->have_to_eat = -1;
	if (pthread_mutex_init(&info->print_mutex, NULL))
		error_in_print_mutex_making(info);
	if (pthread_mutex_init(&info->end_flag_mutex, NULL))
		error_in_print_mutex_making(info);
	if (make_fork(info))
		return (NULL);
	if (init_fork_mutex(info))
		return (NULL);
	gettimeofday(&info->start_time, NULL);
	info->end_flag = 0;
	info->eat_finish = 0;
	return (info);
}
