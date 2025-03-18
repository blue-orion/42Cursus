/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philos_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:51:19 by takwak            #+#    #+#             */
/*   Updated: 2025/03/18 21:37:17 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_philo(t_philo *philo, int idx, t_info *info, t_common *common);
int	stop_make_philos(t_philo *philo, int idx);

t_philo	*make_philos(t_philo *philo, t_info *info, t_common *common)
{
	int	i;

	philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < info->num_of_philo)
	{
		if (init_philo(&philo[i], i, info, common))
		{
			stop_make_philos(philo, i);
			return (NULL);
		}
		philo[i].pid = fork();
		if (philo[i].pid < 0)
		{
			stop_make_philos(philo, i);
			return (NULL);
		}
		if (philo[i].pid == 0)
			philo_routine(philo, i);
		if (philo[i].pid > 0)
			i++;
	}
	return (philo);
}

int	init_philo(t_philo *philo, int idx, t_info *info, t_common *common)
{
	memset(philo, 0, sizeof(t_philo));
	philo->id = idx + 1;
	philo->last_eat_time = info->start_time;
	make_sema_name(philo->stop_sem_name, "/stop", idx + 1);
	sem_unlink(philo->stop_sem_name);
	philo->info = info;
	philo->common = common;
	return (0);
}

int	stop_make_philos(t_philo *philo, int idx)
{
	while (idx)
	{
		if (philo[idx].pid)
			kill(philo[idx].pid, SIGKILL);
		idx--;
	}
	free(philo);
	return (-1);
}
