/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 03:29:36 by takwak            #+#    #+#             */
/*   Updated: 2025/03/17 17:15:58 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_common_resource(t_common *common)
{
	sem_close(common->fork_sem->adr);
	sem_close(common->print_sem->adr);
	sem_unlink("fork");
	sem_unlink("print");
	free(common->fork_sem);
	free(common->print_sem);
}

void	free_philo_resource(t_philo *philo)
{
	sem_close(philo->eat_cnt_sem->adr);
	sem_close(philo->flag_sem->adr);
	sem_close(philo->time_sem->adr);
	free(philo->eat_cnt_sem->name);
	free(philo->flag_sem->name);
	free(philo->time_sem->name);
	free(philo->eat_cnt_sem);
	free(philo->flag_sem);
	free(philo->time_sem);
}

void	unlink_philo_sem(int id)
{
	char	*name;

	name = make_sema_name("/flag", id);
	sem_unlink(name);
	free(name);
	name = make_sema_name("/eat_cnt", id);
	sem_unlink(name);
	free(name);
	name = make_sema_name("/time", id);
	sem_unlink(name);
	free(name);
}

void	free_resources(t_info *info, t_common *common)
{
	int	i;

	i = 0;
	free_common_resource(common);
	{
		unlink_philo_sem(i + 1);
		i++;
	}
	free(info->pid);
}
