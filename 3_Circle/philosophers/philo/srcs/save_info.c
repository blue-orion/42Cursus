/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:39:01 by takwak            #+#    #+#             */
/*   Updated: 2024/12/22 02:21:50 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_info	*save_info(char **argv)
{
	t_info	*info;
	int		i;

	info = (t_info *)malloc(sizeof(t_info));
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		info->have_to_eat = ft_atoi(argv[5]);
	else
		info->have_to_eat = -1;
	info->fork = (int *)malloc(sizeof(int) * info->num_of_philo);
	memset((void *)info->fork, 0, sizeof(int) * info->num_of_philo);
	info->mutex = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * info-> num_of_philo);
	i = 0;
	while (i < info->num_of_philo)
	{
		if (pthread_mutex_init(&info->mutex[i], NULL))
			perror("Error in mutex_init");
		i++;
	}
	if (pthread_mutex_init(&info->print_mutex, NULL))
		perror("Error in mutex_init");
	if (gettimeofday(&info->start_time, NULL))
		perror("Error in gettimeofday");
	info->end = 0;
	return (info);
}
