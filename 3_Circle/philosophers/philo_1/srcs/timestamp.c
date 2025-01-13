/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:20:14 by takwak            #+#    #+#             */
/*   Updated: 2024/12/22 19:44:27 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long	get_current_time(struct timeval *cur, struct timeval *start)
{
	int		flag;
	long	time;
	long	sec;
	long	usec;

	flag = gettimeofday(cur, NULL);
	if (flag == -1)
		return (-1);
	sec = cur->tv_sec - start->tv_sec;
	usec = cur->tv_usec - start->tv_usec;
	time = sec * 1000 + usec / 1000;
	return (time);
}
