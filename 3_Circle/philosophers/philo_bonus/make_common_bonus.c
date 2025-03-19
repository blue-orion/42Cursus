/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_common_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:44:17 by takwak            #+#    #+#             */
/*   Updated: 2025/03/19 16:49:31 by takwak           ###   ########.fr       */
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
	return (0);
}
