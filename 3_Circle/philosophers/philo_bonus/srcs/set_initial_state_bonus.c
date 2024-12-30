/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_initial_state_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 02:39:57 by takwak            #+#    #+#             */
/*   Updated: 2024/12/29 20:38:25 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	save_info(t_info *info, int argc, char **argv)
{
	info->num_of_philo = philo_atoi(argv[1]);
	info->time_to_die = philo_atoi(argv[2]);
	info->time_to_eat = philo_atoi(argv[3]);
	info->time_to_sleep = philo_atoi(argv[4]);
	if (info->num_of_philo <= 0 || info->time_to_die <= 0 ||
		info->time_to_eat <= 0 || info->time_to_sleep <= 0)
		return (1);
	if (argc == 6)
	{
		info->must_eat_time = philo_atoi(argv[5]);
		if (info->must_eat_time <= 0)
			return (1);
	}
	else
		info->must_eat_time = -1;
	gettimeofday(&info->start_time, NULL);
	info->pid = (pid_t *)malloc(sizeof(pid_t) * info->num_of_philo);
	if (!info->pid)
		return (1);
	return (0);
}

int	make_common_resource(t_common *common, t_info info)
{
	common->fork_sem = (t_sem *)malloc(sizeof(t_sem));
	common->fork_sem->adr = open_semaphore("fork", info.num_of_philo);
	common->fork_sem->name = "fork";
	common->print_sem = (t_sem *)malloc(sizeof(t_sem));
	common->print_sem->adr = open_semaphore("print", 1);
	common->print_sem->name = "print";
	if (!common->fork_sem || !common->print_sem)
	{
		sem_close(common->fork_sem->adr);
		sem_unlink("fork");
		sem_close(common->print_sem->adr);
		sem_unlink("print");
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
	philo->info = info;
	philo->common = common;
	philo->flag = -1;
	philo->status = -1;
	philo->eat_cnt_sem = (t_sem *)malloc(sizeof(t_sem));
	philo->eat_cnt_sem->name = make_sema_name("/eat_cnt", idx); 
	philo->eat_cnt_sem->adr = open_semaphore(philo->eat_cnt_sem->name, 1);
	philo->flag_sem = (t_sem *)malloc(sizeof(t_sem));
	philo->flag_sem->name = make_sema_name("/flag", idx);
	philo->flag_sem->adr = open_semaphore(philo->flag_sem->name, 1);
	philo->time_sem = (t_sem *)malloc(sizeof(t_sem));
	philo->time_sem->name = make_sema_name("/time", idx);
	philo->time_sem->adr = open_semaphore(philo->time_sem->name, 1);
	if (!philo->eat_cnt_sem->adr || !philo->eat_cnt_sem->name
		|| !philo->flag_sem->adr || !philo->flag_sem->name
		|| !philo->time_sem->adr || !philo->time_sem->name)
		return (-1);
	philo->last_eat_time.tv_sec = info->start_time.tv_sec;
	philo->last_eat_time.tv_usec = info->start_time.tv_usec;
	return (0);
}

int set_initial_state(t_info *info, t_common *common)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < info->num_of_philo)
	{
		philo = (t_philo *)malloc(sizeof(t_philo));
		if (!philo)
			return (-1);
		if (init_philo(philo, i, info, common))
			return (-1);
		info->pid[i] = fork();
		if (info->pid[i] < 0)
			return (-1);
		else if (info->pid[i] == 0)
			philo_main(philo);
		else
			i++;
		free_philo_resource(philo);
		free(philo);
	}
	return (0);
}
