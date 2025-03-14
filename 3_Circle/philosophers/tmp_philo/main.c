/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:39:52 by takwak            #+#    #+#             */
/*   Updated: 2025/03/14 18:27:27 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_info		info;
	t_common	common;
	t_philo		*philo;
	struct timeval	tv;

	if (ac < 5 || save_info(&info, ac, av))
		return (write(2, "Invalid input\n", 14));
	if (make_common_resources(&common, info))
		return (write(2, "make mutex failed\n", 18));
	philo = make_philos(&info, &common);
	// monitoring();
	// free_resouces();
	sleep(5);
	return (0);
}
