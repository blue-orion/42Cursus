/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:23:52 by takwak            #+#    #+#             */
/*   Updated: 2024/12/21 04:02:13 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*new_philo(void *philo_info)
{
	t_philo	*philo;

	philo = (t_philo *)philo_info;
	for (int i = 0; i < 9; i++)
	{
		usleep(100);
		get_current_time(&philo->cur_time, &philo->start_time);
		if (philo->num % 5 == 1)
			print_log(philo->num, philo->cur_time, FORK);
		if (philo->num % 5 == 2)
			print_log(philo->num, philo->cur_time, EAT);
		if (philo->num % 5 == 3)
			print_log(philo->num, philo->cur_time, SLEEP);
		if (philo->num % 5 == 4)
			print_log(philo->num, philo->cur_time, THINK);
		if (philo->num % 5 == 0)
		{
			print_log(philo->num, philo->cur_time, DIE);
			printf("\n");
		}
	}
	return (NULL);
}

void	init_philo_info(int num, t_info *info, t_philo *philo)
{
	philo->num = num;
	philo->start_time = info->start_time;
}

t_philo	*make_philo(t_info *info)
{
	t_philo	*philoes;
	int	i;

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
