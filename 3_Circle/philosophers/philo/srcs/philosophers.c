/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:11:24 by takwak            #+#    #+#             */
/*   Updated: 2025/01/15 15:51:40 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	t_info		info;
	t_common	common;
	t_philo		*philo;

	if (argc < 5)
		return (1);
	save_info(&info, argc, argv);
	if (make_common_resource(&common, &info))
		return (-1);
	philo = set_init_state(&info, &common);
	if (!philo)
		return (destroy_all_mutex(&info, &common));
	monitoring(philo);
	end_process(philo);
	return (0);
}
