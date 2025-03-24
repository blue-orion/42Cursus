/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:34:43 by takwak            #+#    #+#             */
/*   Updated: 2025/03/21 20:27:29 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	stop_make_philo(t_philo *philo, int num);
void	init_philo(t_philo *philo, int i, t_info *info, t_common *common);

t_philo	*make_philos(t_info *info, t_common *common)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (!philo)
		return (NULL);
	while (i < info->num_of_philo)
	{
		init_philo(&philo[i], i, info, common);
		if (pthread_mutex_init(&philo[i].stop.lock, NULL))
		{
			philo[i].stop.value = 1;
			stop_make_philo(philo, i);
			return (NULL);
		}
		if (pthread_create(&philo[i].tid, NULL, &philo_routine, &philo[i]))
		{
			stop_make_philo(philo, i);
			return (NULL);
		}
		i++;
	}
	return (philo);
}

void	init_philo(t_philo *philo, int i, t_info *info, t_common *common)
{
	philo->id = i + 1;
	philo->left = i;
	philo->right = (i + 1) % info->num_of_philo;
	philo->eat_cnt = 0;
	philo->last_eat_time = info->start_time;
	philo->info = info;
	philo->common = common;
	philo->stop.value = 0;
}

void	stop_make_philo(t_philo *philo, int num)
{
	int	i;

	i = 0;
	while (i < num)
		pthread_join(philo[i++].tid, NULL);
	i = num;
	while (i >= 0)
	{
		if (!philo[i].stop.value)
			pthread_mutex_destroy(&philo[i].stop.lock);
		i--;
	}
	free(philo);
}
