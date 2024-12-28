/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:33:33 by takwak            #+#    #+#             */
/*   Updated: 2024/12/28 17:56:51 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	main(int argc, char **argv)
{
	t_philo	*philos;

	if (argc < 5 || argc > 6)
		return (write(2, "Invalid argument\n", 17), 0);
	philos = set_initial_state(argc, argv);
	if (!philos)
		error_exit();
	if (wait_end_philo(philos))
		success_exit(philos);
	return (0);
}
