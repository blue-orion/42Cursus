/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:07:15 by takwak            #+#    #+#             */
/*   Updated: 2025/03/13 22:17:39 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_log(t_philo *info, int time, int status)
{
	while (get_value(&info->common->print))
		usleep(20);
	set_value(&info->common->print, 1);
	if (status == FORK)
		printf("%d %d has taken a fork\n", time, info->id);
	if (status == EAT)
		printf("%d %d is eating\n", time, info->id);
	if (status == SLEEP)
		printf("%d %d is sleeping\n", time, info->id);
	if (status == THINK)
		printf("%d %d is thinking\n", time, info->id);
	if (status == DIE)
		printf("%d %d is died\n", time, info->id);
	set_value(&info->common->print, 0);
}
