/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:44:04 by takwak            #+#    #+#             */
/*   Updated: 2025/03/11 22:07:05 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_runtime(struct timeval start_time)
{
	struct timeval	cur_time;
	int				runtime;
	int				sec;
	int				usec;

	gettimeofday(&cur_time, NULL);
	sec = cur_time.tv_sec - start_time.tv_sec;
	usec = cur_time.tv_usec - start_time.tv_usec;
	runtime = sec * 1000 + usec / 1000;
	return (runtime);
}
