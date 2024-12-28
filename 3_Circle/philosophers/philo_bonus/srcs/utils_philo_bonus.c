/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 04:15:39 by takwak            #+#    #+#             */
/*   Updated: 2024/12/29 04:25:58 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	set_status(t_philo *philo, t_status status)
{
	if (status == FINISH)
		philo->status = FINISH;
	if (status == DIE)
		philo->status = DIE;
	if (status == FORK)
		philo->status = FORK;
	if (status == EAT)
		philo->status = EAT;
	if (status == SLEEP)
		philo->status = SLEEP;
	if (status == THINK)
		philo->status = THINK;
}
