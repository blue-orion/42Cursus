/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_init_state.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:14:24 by takwak            #+#    #+#             */
/*   Updated: 2025/01/14 00:11:58 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	save_info(t_info *dst, int argc, char **argv)
{
	dst->num_of_philo = philo_atoi(argv[1]);
	dst->time_to_die = philo_atoi(argv[2]);
	dst->time_to_eat = philo_atoi(argv[3]);
	dst->time_to_sleep = philo_atoi(argv[4]);
	if (argc == 6)
		dst->must_eat = philo_atoi(argv[5]);
	else
		dst->must_eat = -1;
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
		if (pthread_mutex_init(&rsc->fork[i], NULL))
			return (-1);
		i++;
	}
	if (pthread_mutex_init(&rsc->log, NULL))
		return (-1);
	if (pthread_mutex_init(&rsc->die, NULL))
		return (-1);
	rsc->dead_flag = 0;
	return (0);
}

void	init_philo_data(int id, t_philo *philo, t_info *info, t_common *common)
{
	memset(philo, 0, sizeof(t_philo));
	philo->id = id;
	philo->left = id - 1;
	philo->right = id % info->num_of_philo;
	philo->info = info;
	philo->common = common;
	gettimeofday(&philo->start_time, NULL);
	gettimeofday(&philo->last_eat_time, NULL);
}

t_philo	*set_init_state(t_info *info, t_common *common)
{
	t_philo	*philo;
	int	i;

	philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < info->num_of_philo)
	{
		init_philo_data(i + 1, &philo[i], info, common);
		if (pthread_create(&philo[i].tid, NULL, 
					 philo_routine, &philo[i]))
			return (NULL);
		i++;
	}
	return (philo);
}
