/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:39:52 by takwak            #+#    #+#             */
/*   Updated: 2025/03/20 12:26:37 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_philo *philo);
void	free_resources(t_philo *philo);

int	main(int ac, char **av)
{
	t_info		info;
	t_common	common;
	t_philo		*philo;

	if (ac < 5 || ac > 6 || save_info(&info, ac, av))
		return (write(2, "Invalid input\n", 14));
	if (make_common_resources(&common, info))
		return (write(2, "make mutex failed\n", 18));
	philo = make_philos(&info, &common);
	monitoring(philo);
	join_threads(philo);
	free_resources(philo);
	return (0);
}

void	join_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->num_of_philo)
	{
		if (pthread_join(philo[i].tid, NULL))
			perror("join failed");
		i++;
	}
}

void	free_resources(t_philo *philo)
{
	destroy_fork_mutex(philo->common->fork, philo->info->num_of_philo - 1);
	pthread_mutex_destroy(&philo->common->print.lock);
	pthread_mutex_destroy(&philo->common->stop.lock);
	free(philo);
}
