/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 02:32:47 by takwak            #+#    #+#             */
/*   Updated: 2024/12/29 03:29:38 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	error_exit(char *s, t_philo *philos)
{
	int	num;
	int	i;

	perror(s);
	if (!philos)
		return (1);
	num = philos->info->num_of_philo;
	i = 0;
	free(philos);
	return (1);
}
