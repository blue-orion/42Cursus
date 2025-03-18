/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:18:56 by takwak            #+#    #+#             */
/*   Updated: 2025/03/18 23:03:27 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_resources(t_philo *philo);

int	main(int ac, char **av)
{
	t_info	info;
	t_common	common;
	t_philo	*philo;

	philo = NULL;
	if (ac < 5 || save_info(&info, ac, av))
		return (write(2, "Invalid Input\n", 14));
	if (make_common(&info, &common))
		return (write(2, "Failed semaphore init\n", 22));
	philo = make_philos(philo, &info, &common);
	monitoring(philo);
	free_resources(philo);
	return (0);
}

void	free_resources(t_philo *philo)
{
	int	i;

	ft_sem_destroy(philo->common->fork, "/fork");
	ft_sem_destroy(philo->common->print, "/print");
	i = 0;
	while (i < philo->info->num_of_philo)
	{
		ft_sem_destroy(philo[i].stop, philo[i].stop_sem_name);
		i++;
	}
	free(philo);
}
