/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:23:52 by takwak            #+#    #+#             */
/*   Updated: 2024/12/22 02:17:05 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*new_philo(void *philo_info)
{
	t_philo	*philo;

	philo = (t_philo *)philo_info;
	if (philo->num % 2 == 0)
		philo_think(philo);
	while (1)
	{
		if (philo->left_fork && philo->right_fork)
			philo_eat(philo);
		if (philo->status == EAT)
			philo_sleep(philo);
		if (philo->info->fork[philo->num - 1])
			philo_think(philo);
		pick_up_right_fork(philo);
		if (philo->info->fork[philo->num % philo->info->num_of_philo])
			philo_think(philo);
		pick_up_left_fork(philo);
	}
	return (NULL);
}

void	init_philo_info(int num, t_info *info, t_philo *philo)
{
	philo->info = info;
	philo->num = num;
	philo->eat_num = 0;
	philo->left_fork = 0;
	philo->right_fork = 0;
	philo->last_eat_time.tv_sec = info->start_time.tv_sec;
	philo->last_eat_time.tv_usec = info->start_time.tv_usec;
	philo->status = -1;
}

t_philo	*make_philo(t_info *info)
{
	t_philo	*philoes;
	int		i;

	philoes = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	i = 0;
	while (i < info->num_of_philo)
	{
		init_philo_info(i + 1, info, &philoes[i]);
		pthread_create(&philoes[i].tid, NULL, new_philo, (void *)&philoes[i]);
		i++;
	}
	return (philoes);
}
