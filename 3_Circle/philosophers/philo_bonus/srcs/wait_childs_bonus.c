/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_childs_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:41:59 by takwak            #+#    #+#             */
/*   Updated: 2024/12/30 02:41:59 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	wait_childs(t_info *info)
{
	int	end_status;
	int	i;

	waitpid(0, &end_status, 0);
	i = 1;
	while (i < info->num_of_philo)
	{
		if (end_status)
			kill(info->pid[i], SIGKILL);
		else
			waitpid(0, &end_status, 0);
		i++;
	}
}
