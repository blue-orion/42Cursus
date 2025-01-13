/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:00:29 by takwak            #+#    #+#             */
/*   Updated: 2024/12/22 22:57:38 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	pick_up_left_fork(t_philo *philo)
{
	int		left_num ;
	long	time;

	if (check_dead_flag(philo))
		return (1);
	left_num = philo->num % philo->info->num_of_philo;
	if (pthread_mutex_lock(&philo->info->fork_mutex[left_num]))
		perror("mutex_lock");
	philo->left_fork = 1;
	philo->info->fork[left_num] = 1;
	philo->status = FORK;
	time = get_current_time(&philo->cur_time, &philo->info->start_time);
	print_log(philo, time);
	return (0);
}

int	pick_up_right_fork(t_philo *philo)
{
	int		right_num ;
	long	time;

	if (check_dead_flag(philo))
		return (1);
	right_num = philo->num - 1;
	if (pthread_mutex_lock(&philo->info->fork_mutex[right_num]))
		perror("mutex_lock");
	philo->right_fork = 1;
	philo->info->fork[right_num] = 1;
	philo->status = FORK;
	time = get_current_time(&philo->cur_time, &philo->info->start_time);
	print_log(philo, time);
	return (0);
}

int	put_down_left_fork(t_philo *philo)
{
	int		left_num ;

	left_num = philo->num % philo->info->num_of_philo;
	if (pthread_mutex_unlock(&philo->info->fork_mutex[left_num]))
		perror("mutex_unlock");
	philo->left_fork = 0;
	philo->info->fork[left_num] = 0;
	return (0);
}

int	put_down_right_fork(t_philo *philo)
{
	int		right_num ;

	right_num = philo->num - 1;
	if (pthread_mutex_unlock(&philo->info->fork_mutex[right_num]))
		perror("mutex_unlock");
	philo->right_fork = 0;
	philo->info->fork[right_num] = 0;
	return (0);
}
