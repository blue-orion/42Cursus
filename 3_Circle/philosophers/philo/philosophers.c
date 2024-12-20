/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:22:24 by takwak            #+#    #+#             */
/*   Updated: 2024/12/21 03:02:53 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int main(int argc, char **argv)
{
	t_info		*info;
	t_philo		*philo;
	pthread_t	tid;
	int			t_param;

	if (argc < 5)
		return (printf("Invalid argv\n"));
	info = save_info(argv);
	philo = make_philo(info);
	sleep(10);
	return (0);
}
