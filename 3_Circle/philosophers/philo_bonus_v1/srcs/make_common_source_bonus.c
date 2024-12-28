/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_common_source_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:27:45 by takwak            #+#    #+#             */
/*   Updated: 2024/12/29 00:15:46 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	make_common_source(t_common *common, t_info *info)
{
	if (gettimeofday(&common->start_time, NULL))
		return (1);
	common->fork_sem = sem_open("fork", O_CREAT | O_EXCL, 644, info->num_of_philo);
	if (!common->fork_sem)
	{
		sem_unlink("fork");
		common->fork_sem = sem_open("fork", O_CREAT | O_EXCL, 644, info->num_of_philo);
	}
	common->print_sem = sem_open("print", O_CREAT | O_EXCL, 644, 1);
	if (!common->print_sem)
	{
		sem_unlink("print");
		common->print_sem = sem_open("print", O_CREAT | O_EXCL, 644, info->num_of_philo);
	}
	if (!common->fork_sem || !common->print_sem)
		return (1);
	return (0);
}
