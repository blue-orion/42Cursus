/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:11:24 by takwak            #+#    #+#             */
/*   Updated: 2025/01/12 18:08:14 by takwak           ###   ########.fr       */
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
	if (save_info(&info, argc, argv))
		return (-1);
	if (make_common_resource(&common, &info))
		return (-1);
	philo = set_init_state(&info, &common);
	return (0);
}

