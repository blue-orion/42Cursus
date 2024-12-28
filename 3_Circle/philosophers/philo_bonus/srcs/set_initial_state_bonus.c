/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_initial_state_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 02:39:57 by takwak            #+#    #+#             */
/*   Updated: 2024/12/29 04:04:36 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	save_info(t_info *info, int argc, char **argv)
{
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (info->num_of_philo <= 0 || info->time_to_die <= 0 ||
		info->time_to_eat <= 0 || info->time_to_sleep <= 0)
		return (1);
	if (argc == 6)
	{
		info->must_eat_time = ft_atoi(argv[5]);
		if (info->must_eat_time <= 0)
			return (1);
	}
	else
		info->must_eat_time = -1;
	gettimeofday(&info->start_time, NULL);
	return (1);
}

int	make_common_resource(t_common *common, t_info info)
{
	common->fork_sem = sem_open("fork", O_CREAT | O_EXCL,
							 0644, info.num_of_philo);
	if (!common->fork_sem)
	{
		sem_unlink("fork");
		common->fork_sem = sem_open("fork", O_CREAT | O_EXCL,
								0644, info.num_of_philo);
	}
	if (!common->fork_sem)
		return (-1);
	common->print_sem = sem_open("print", O_CREAT | O_EXCL,
							  0644, 1);
	if (!common->print_sem)
	{
		sem_unlink("print");
		common->print_sem = sem_open("print", O_CREAT | O_EXCL,
								0644, info.num_of_philo);
	}
	if (!common->print_sem)
	{
		sem_unlink("fork");
		return (-1);
	}
	return (0);
}

int	init_philo(t_philo *philo, int idx, t_info *info, t_common *common)
{
	philo = (t_philo *)memset(philo, 0, sizeof(t_philo));
	if (!philo)
		return (-1);
	philo->id = idx + 1;
	philo->status = -1;
	philo->info = info;
	philo->common = common;
	return (1);
}

t_philo	*set_initial_state(t_info *info, t_common *common)
{
	int		i;
	t_philo	*philos;

	philos = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo + 1);
	i = 0;
	while (i < info->num_of_philo)
	{
		if (init_philo(&philos[i], i, info, common))
			break ;
		philos[i].pid = fork();
		if (philos[i].pid < 0)
			break ;
		else if (philos[i].pid == 0)
			philo_main(&philos[i]);
		else
			i++;
	}
	return (philos);
}
