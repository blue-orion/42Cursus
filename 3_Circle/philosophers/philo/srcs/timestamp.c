/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:20:14 by takwak            #+#    #+#             */
/*   Updated: 2024/12/21 04:00:22 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	get_current_time(struct timeval *cur, struct timeval *start)
{
	int	flag;
	
	flag = gettimeofday(cur, NULL);
	if (flag == -1)
		return (-1);
	cur->tv_sec = cur->tv_sec - start->tv_sec;
	cur->tv_usec = cur->tv_sec * 1000 + cur->tv_usec - start->tv_usec;
	return (0);
}
