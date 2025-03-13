/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:08:16 by takwak            #+#    #+#             */
/*   Updated: 2025/03/13 22:17:12 by takwak           ###   ########.fr       */
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
