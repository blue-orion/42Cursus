/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 23:01:53 by takwak            #+#    #+#             */
/*   Updated: 2024/12/29 01:47:45 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	*free_common(t_common *common)
{
	int	error;

	if (common->fork_sem)
	{
		error = sem_close(common->fork_sem);
		error = sem_unlink("fork");
	}
	if (common->print_sem)
	{
		error = sem_close(common->print_sem);
		error = sem_unlink("print");
	}
	printf("errno : %d\n", error);
	return (NULL);
}
