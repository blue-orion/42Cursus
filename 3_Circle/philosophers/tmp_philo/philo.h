/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:05:40 by takwak            #+#    #+#             */
/*   Updated: 2025/03/12 21:46:47 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct	s_info
{
	int	num_of_philo;
	int	time_of_die;
	int	time_of_eat;
	int	time_of_sleep;
	int	must_eat_cnt;
}	t_info;

typedef struct	s_mutex
{
	int				value;
	pthread_mutex_t	*lock;
}	t_mutex;

typedef struct	s_common
{
	t_mutex			*fork;
	t_mutex			*die;
	pthread_mutex_t	*print;
}	t_common;

#endif
