/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:05:40 by takwak            #+#    #+#             */
/*   Updated: 2025/03/19 18:01:47 by takwak           ###   ########.fr       */
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
	FORK = 1,
	EAT,
	SLEEP,
	THINK,
	DIE,
	COUNTED
};

typedef struct s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_cnt;
	struct timeval	start_time;
}	t_info;

typedef struct s_mutex
{
	int				value;
	pthread_mutex_t	lock;
}	t_mutex;

typedef struct s_common
{
	t_mutex	*fork;
	t_mutex	print;
	t_mutex	stop;
}	t_common;

typedef struct s_philo
{
	pthread_t			tid;
	int					id;
	int					left;
	int					right;
	struct timeval		last_eat_time;
	int					cur_time;
	t_mutex				stop;
	int					eat_cnt;
	t_info				*info;
	t_common			*common;
}	t_philo;

//Main
t_philo	*make_philos(t_info *info, t_common *common);
int		save_info(t_info *info, int ac, char **av);
int		make_common_resources(t_common *common, t_info info);
int		get_runtime(struct timeval start);
void	print_log(t_philo *info, int time, int status);

//Mutex Utils
void	set_value(t_mutex *mtx, int value);
int		get_value(t_mutex *mtx);
void	destroy_fork_mutex(t_mutex *fork, int i);

//Philo routine
void	*philo_routine(void *data);
void	philo_fork(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
int		philo_stop(t_philo *philo);
int		philo_die(t_philo *philo);
void	philo_fork(t_philo *philo);

int		ft_philo_atoi(char *s);
void	ft_usleep(t_philo *philo, int time);
void	monitoring(t_philo *philo);
void	end_philo(t_philo *philo);
#endif
