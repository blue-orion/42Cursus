/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:07:39 by takwak            #+#    #+#             */
/*   Updated: 2025/03/13 19:07:57 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_mutex_destroy(t_mutex *fork, int i)
{
	while (i >= 0)
	{
		pthread_mutex_destroy(&fork[i].lock);
		i--;
	}
	free(fork);
}
