/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 03:29:36 by takwak            #+#    #+#             */
/*   Updated: 2024/12/30 03:29:36 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	free_common_resource(t_common *common)
{
	sem_post(common->fork_sem->adr);
	sem_post(common->fork_sem->adr);
	sem_post(common->fork_sem->adr);
	sem_post(common->fork_sem->adr);
	sem_post(common->fork_sem->adr);
	sem_post(common->fork_sem->adr);
	sem_post(common->fork_sem->adr);
	sem_post(common->fork_sem->adr);
	sem_post(common->fork_sem->adr);
	sem_post(common->print_sem->adr);
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
	sem_unlink(philo->eat_cnt_sem->name);
	sem_unlink(philo->flag_sem->name);
	sem_unlink(philo->time_sem->name);
	free(philo->eat_cnt_sem->name);
	free(philo->flag_sem->name);
	free(philo->time_sem->name);
	free(philo->eat_cnt_sem);
	free(philo->flag_sem);
	free(philo->time_sem);
}

void	free_resources(t_philo *philo)
{
	int	i;

	free_common_resource(philo->common);
	i = 0;
	while (i < philo->info->num_of_philo)
	{
		free_philo_resource(&philo[i]);
		i++;
	}
	free(philo);
}
