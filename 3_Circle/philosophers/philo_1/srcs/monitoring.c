/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:25:23 by takwak            #+#    #+#             */
/*   Updated: 2024/12/23 01:53:23 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <pthread.h>

int	check_dead_flag(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->end_flag_mutex);
	if (philo->info->end_flag)
	{
		pthread_mutex_unlock(&philo->info->end_flag_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->end_flag_mutex);
	return (0);
}

int	monitoring(t_philo *philos)
{
	int	i;

	while (1)
	{
		i = -1;
		usleep(100);
		while (++i < philos->info->num_of_philo)
		{
			if (have_to_die(&philos[i]))
				return (1);
			if (philos[i].eat_num == philos->info->have_to_eat)
			{
				philos->info->eat_finish += 1;
				philos[i].eat_num += 1;
			}
		}
		if (philos->info->eat_finish == philos->info->num_of_philo)
			break ;
	}
	return (1);
}

int	print_log(t_philo *philo, long cur_time)
{
	int	err_flag;

	if (check_dead_flag(philo))
		return (1);
	pthread_mutex_lock(&philo->info->print_mutex);
	err_flag = 0;
	err_flag = printf("%ld ", cur_time);
	if (philo->status == FORK)
		err_flag = printf("%d has taken a fork\n", philo->num);
	if (philo->status == EAT)
		err_flag = printf("%d is eating\n", philo->num);
	if (philo->status == SLEEP)
		err_flag = printf("%d is sleeping\n", philo->num);
	if (philo->status == THINK)
		err_flag = printf("%d is thinking\n", philo->num);
	if (philo->status == DIE)
		err_flag = printf("%d is died\n", philo->num);
	if (err_flag < 0)
		perror("error in print_log");
	pthread_mutex_unlock(&philo->info->print_mutex);
	return (0);
}
