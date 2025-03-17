/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:17:00 by takwak            #+#    #+#             */
/*   Updated: 2025/03/17 16:17:21 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_value(t_mutex *mtx)
{
	int	value;

	pthread_mutex_lock(&mtx->lock);
	value = mtx->value;
	pthread_mutex_unlock(&mtx->lock);
	return (value);
}

void	set_value(t_mutex *mtx, int value)
{
	pthread_mutex_lock(&mtx->lock);
	mtx->value = value;
	pthread_mutex_unlock(&mtx->lock);
}

void	destroy_fork_mutex(t_mutex *fork, int i)
{
	while (i >= 0)
	{
		pthread_mutex_destroy(&fork[i].lock);
		i--;
	}
	free(fork);
}
