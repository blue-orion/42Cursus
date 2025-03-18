/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:58:23 by takwak            #+#    #+#             */
/*   Updated: 2025/03/18 23:38:17 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitoring_thread(void *data);
void	*check_die_thread(void *data);

void	monitoring(t_philo *philo)
{
	int	status;
	pthread_t	check_die;
	pthread_t	monitor;

	pthread_create(&monitor, NULL, &monitoring_thread, philo);
	pthread_create(&check_die, NULL, &check_die_thread, philo);
	pthread_join(check_die, (void *)&status);
	pthread_join(monitor, (void *)&status);
}

void	*monitoring_thread(void *data)
{
	t_philo	*philo;
	sem_t	*stop;
	int		i;
	int		finish;

	philo = (t_philo *)data;
	finish = 0;
	while (1)
	{
		i = 0;
		while (i < philo->info->num_of_philo)
		{
			stop = sem_open(philo[i].stop_sem_name, 0);
			if (stop)
			{
				finish++;
				sem_close(stop);
				sem_unlink(philo[i].stop_sem_name);
			}
			i++;
		}
		if (finish == philo->info->num_of_philo)
			break ;
		ft_usleep(500);
	}
	stop = ft_sem_open("stop", philo->info->num_of_philo);
	sem_post(philo->common->die);
	printf("make stop semaphore\n");
	i = 0;
	while (i < philo->info->num_of_philo)
	{
		waitpid(philo[i].pid, NULL, 0);
		i++;
	}
	printf("all philos waited\n");
	ft_sem_destroy(stop, "stop");
	return ((void *)EAT);
}

void	*check_die_thread(void *data)
{
	t_philo	*philo;
	int		i;
	sem_t	*stop;

	philo = (t_philo *)data;
	sem_wait(philo->common->die);
	stop = sem_open("stop", 0);
	if (stop)
	{
		sem_close(stop);
		return (NULL);
	}
	printf("died........\n");
	i = 0;
	while (i < philo->info->num_of_philo)
	{
		kill(philo[i].pid, SIGKILL);
		i++;
	}
	return ((void *)DIE);
}
