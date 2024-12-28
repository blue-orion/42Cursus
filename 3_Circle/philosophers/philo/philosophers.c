/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:22:24 by takwak            #+#    #+#             */
/*   Updated: 2024/12/26 00:48:43 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	t_info	*info;
	t_philo	*philo;

	if (argc < 5)
		return (printf("Invalid argv\n"));
	info = save_info(argv);
	philo = make_philo(info);
	if (monitoring(philo))
	{
		pthread_mutex_lock(&info->end_flag_mutex);
		info->end_flag = 1;
		pthread_mutex_unlock(&info->end_flag_mutex);
	}
	end_process(info, philo);
	return (0);
}
