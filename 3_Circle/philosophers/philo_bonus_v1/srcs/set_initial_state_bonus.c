/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_initial_state_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:26:21 by takwak            #+#    #+#             */
/*   Updated: 2024/12/29 01:27:20 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	init_philo(t_philo *philo, int id, t_info *info, t_common *common)
{
	philo->id = id;
	philo->status = -1;
	philo->eat_cnt = 0;
	philo->having_fork_num = 0;
	philo->flag = 0;
	philo->info = info;
	philo->common = common;
	philo->last_eat_time.tv_sec = common->start_time.tv_sec;
	philo->last_eat_time.tv_usec = common->start_time.tv_usec;
	philo->time_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	philo->flag_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philo->time_mutex, NULL);
	pthread_mutex_init(philo->flag_mutex, NULL);
}

t_philo	*set_initial_state(int argc, char **argv)
{
	pid_t		pid;
	t_info		*info;
	t_common	common;
	t_philo		*philos;
	int			i;

	info = save_info(argc, argv);
	if (!info)
		return (NULL);
	if (make_common_source(&common, info))
		return (free(info), NULL);
	philos = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (!philos)
		return (free(info), free_common(&common), NULL);
	i = 0;
	pid = 1;
	while (pid > 0 && i < info->num_of_philo)
	{
		init_philo(&philos[i], i + 1, info, &common);
		pid = fork();
		if (pid == -1)
			perror("fork error");
		if (pid == 0)
			start_action(&philos[i]);
		else
			philos[i].pid = pid;
		i++;
	}
	return (philos);
}
