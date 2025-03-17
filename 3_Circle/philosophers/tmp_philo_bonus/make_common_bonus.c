/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_common_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:44:17 by takwak            #+#    #+#             */
/*   Updated: 2025/03/17 21:48:03 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	make_common(t_info *info, t_common *common)
{
	common->print = ft_sem_open("/print", 1);
	if (!common->print)
		return (-1);
	common->fork = ft_sem_open("/fork", info->num_of_philo);
	if (!common->fork)
	{
		sem_close(common->print);
		sem_unlink("/print");
		return (-1);
	}
	common->end.lock = ft_sem_open("/end", 1);
	if (!common->end.lock)
	{
		sem_close(common->print);
		sem_unlink("/print");
		sem_close(common->fork);
		sem_unlink("/fork");
		return (-1);
	}
	common->end.value = malloc(sizeof(int));
	*common->end.value = 0;
	return (0);
}
