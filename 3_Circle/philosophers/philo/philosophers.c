/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:22:24 by takwak            #+#    #+#             */
/*   Updated: 2024/12/22 02:16:00 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	t_info	*info;
	t_philo	*philo;
	int		i;

	if (argc < 5)
		return (printf("Invalid argv\n"));
	info = save_info(argv);
	philo = make_philo(info);
	while (1)
	{
		i = -1;
		while (++i < info->num_of_philo)
		{
			if (have_to_die(&philo[i]))
				return (0);
			if (philo[i].eat_num == info->have_to_eat)
			{
				info->end += 1;
				philo[i].eat_num += 1;
			}
		}
		if (info->end == info->num_of_philo)
			break ;
	}
	return (0);
}
