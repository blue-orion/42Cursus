/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 01:56:05 by takwak            #+#    #+#             */
/*   Updated: 2024/12/29 20:04:33 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	main(int argc, char **argv)
{
	t_info		info;
	t_common	common;

	if (argc < 5 || argc > 6)
		return (error_exit("Too few or many arguments"));
	if (save_info(&info, argc, argv))
		return (error_exit("Invalid argv value"));
	if (make_common_resource(&common, info))
		return (error_exit("Error in making common resources"));
	if (set_initial_state(&info, &common))
		return (error_exit("Error in setting initial state"));
	wait_childs(&info);
	free_resources(&info, &common);
	return (0);
}
