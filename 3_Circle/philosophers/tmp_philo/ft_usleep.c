/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:48:03 by takwak            #+#    #+#             */
/*   Updated: 2025/03/16 19:47:26 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int time)
{
	struct timeval	start;
	struct timeval	cur;
	int				runtime;

	gettimeofday(&start, NULL);
	while (1)
	{
		gettimeofday(&cur, NULL);
		runtime = (cur.tv_sec - start.tv_sec) * 1000
			+ (cur.tv_usec - start.tv_usec) / 1000;
		if (runtime >= time)
			break ;
		usleep(30);
	}
}
