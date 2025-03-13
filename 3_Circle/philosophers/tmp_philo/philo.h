/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:05:40 by takwak            #+#    #+#             */
/*   Updated: 2025/03/13 22:28:43 by takwak           ###   ########.fr       */
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

enum
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
};

typedef struct	s_info
{
	int	num_of_philo;
	int	time_of_die;
	int	time_of_eat;
	int	time_of_sleep;
	int	must_eat_cnt;
	int	start_time;
}	t_info;

typedef struct	s_mutex
{
	int				value;
	pthread_mutex_t	lock;
}	t_mutex;

typedef struct	s_common
{
	t_mutex	*fork;
	t_mutex	print;
	t_mutex	stop;
}	t_common;

typedef struct	s_philo
{
	pthread_t		tid;
	int				id;
	int				left;
	int				right;
	int				eat_cnt;
	int				last_eat_time;
	int				cur_time;
	t_mutex			die;
	t_info			*info;
	t_common		*common;
}	t_philo;

int		ft_philo_atoi(char *s);
int		save_info(t_info *info, int ac, char **av);
void	fork_mutex_destroy(t_mutex *fork, int i);
int		make_common_resources(t_common *common, t_info info);
int		get_time(void);
void	set_value(t_mutex *mtx, int value);
int		get_value(t_mutex *mtx);
void	print_log(t_philo *info, int time, int status);

//Act
int		philo_die(t_philo *philo);
void	philo_fork(t_philo *philo);
#endif
