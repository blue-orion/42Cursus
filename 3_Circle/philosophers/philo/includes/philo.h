/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:06:26 by takwak            #+#    #+#             */
/*   Updated: 2025/01/15 16:29:44 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/wait.h>
# include <sys/time.h>

enum
{
	DIE = 0,
	FORK,
	EAT,
	SLEEP,
	THINK,
	FINISH,
	EXIT
};

typedef struct s_info
{
	int		num_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat;
}	t_info;

typedef struct s_common
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	log;
	pthread_mutex_t	die;
	int				dead_flag;
}	t_common;

typedef struct s_philo
{
	pthread_t		tid;
	int				id;
	int				left;
	int				right;
	int				status;
	int				eat_cnt;
	struct timeval	start_time;
	struct timeval	last_eat_time;
	int				runtime;
	t_info			*info;
	t_common		*common;
}	t_philo;

//Set init state
void	save_info(t_info *dst, int argc, char **argv);
int		make_common_resource(t_common *rsc, t_info *info);
t_philo	*set_init_state(t_info *info, t_common *common);

//Philo_routine
void	*philo_routine(void *data);
int		philo_fork(t_philo *philo);
int		philo_eat(t_philo *philo);
int		philo_sleep(t_philo *philo);
int		philo_think(t_philo *philo);
int		philo_die(t_philo *philo);

//Philo Utils
int		is_stop(t_philo *philo);
//Logs
int		print_log(t_philo *philo, int runtime);
//Monitoring
void	monitoring(t_philo *philo);
int		check_dead(t_philo *philo);

//End process
void	end_process(t_philo *philo);

//Utils
int		philo_atoi(const char *nptr);
int		get_runtime(struct timeval start_time);
int		destory_fork_mutex(pthread_mutex_t *forks, int num);
int		destroy_all_mutex(t_info *info, t_common *common);
int		unlock_all_mutex(t_info *info, t_common *common);
void	*detach_all(t_philo *philos, int num);

#endif
