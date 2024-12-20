/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:39:01 by takwak            #+#    #+#             */
/*   Updated: 2024/12/21 03:52:41 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <sys/time.h>

t_info	*save_info(char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	gettimeofday(&info->start_time, NULL);
	return (info);
}
