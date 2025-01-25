/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 01:56:05 by takwak            #+#    #+#             */
/*   Updated: 2025/01/25 18:14:59 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	main(int argc, char **argv)
{
	t_info		info;
	t_common	common;

	if (argc < 5 || argc > 6)
		return (write(2, "Too few or many arguments\n", 26));
	if (save_info(&info, argc, argv))
		return (write(2, "Invalid argv value\n", 19));
	if (make_common_resource(&common, info))
		return (write(2, "Error in making common resources\n", 33));
	if (set_initial_state(&info, &common))
		return (write(2, "Error in setting initial state\n", 31));
	wait_childs(&info);
	free_resources(&info, &common);
	return (0);
}
