/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:44:04 by takwak            #+#    #+#             */
/*   Updated: 2025/01/13 20:42:23 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	get_runtime(t_philo *philo, struct timeval start_time)
{
	int	runtime;
	int	sec;
	int	usec;

	gettimeofday(&philo->cur_time, NULL);
	sec = philo->cur_time.tv_sec - start_time.tv_sec;
	usec = philo->cur_time.tv_usec - start_time.tv_usec;
	runtime = sec * 1000 + usec / 1000;
	return (runtime);
}
