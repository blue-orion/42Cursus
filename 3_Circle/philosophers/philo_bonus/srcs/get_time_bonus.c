/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:44:04 by takwak            #+#    #+#             */
/*   Updated: 2024/12/28 01:51:58 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	get_runtime(struct timeval cur, struct timeval start)
{
	int	runtime;
	int	sec;
	int	usec;

	sec = cur.tv_sec - start.tv_sec;
	usec = cur.tv_usec - start.tv_usec;
	runtime = sec * 1000 + usec / 1000;
	return (runtime);
}
