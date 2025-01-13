/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_init_state.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:14:24 by takwak            #+#    #+#             */
/*   Updated: 2025/01/13 17:39:56 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	save_info(t_info *dst, int argc, char **argv)
{
	dst->num_of_philo = ft_atoi(argv[1]);
	dst->time_to_die = ft_atoi(argv[2]);
	dst->time_to_eat = ft_atoi(argv[3]);
	dst->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		dst->must_eat = ft_atoi(argv[5]);
	else
		dst->must_eat = -1;
	return (-1);
}

int	make_common_resource(t_common *rsc, t_info *info)
{
	int	i;

	rsc->fork = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * info->num_of_philo);
	if (!rsc->fork)
		return (-1);
	i = 0;
	while (i < info->num_of_philo)
	{
		if (pthread_mutex_init(rsc->fork, NULL))
			return (-1);
		i++;
	}
	return (0);
}

void	init_philo_data(t_philo *philo, t_info *info, t_common *common)
{
	memset(philo, 0, sizeof(t_philo));
	philo->status = 0;
	philo->info = info;
	philo->common = common;
	gettimeofday(&philo->start_time, NULL);
}

t_philo	*set_init_state(t_info *info, t_common *common)
{
	t_philo	philo;
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	{
		philo.id = i + 1;
		pthread_create(&philo.tid, NULL, philo_routine, &philo);
		i++;
	}
	return (NULL);
}
