/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:06:26 by takwak            #+#    #+#             */
/*   Updated: 2025/01/13 18:12:16 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/wait.h>
# include <sys/time.h>

enum
{
	DIE = 0,
	EAT,
	SLEEP,
	THINK,
	FINISH,
	FORK
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
	pthread_mutex_t die;
}	t_common;

typedef struct s_philo
{
	pthread_t		tid;
	int				id;
	int				status;
	int				eat_cnt;
	struct timeval	start_time;
	struct timeval	cur_time;
	struct timeval	last_eat_time;
	int				runtime;
	t_info			*info;
	t_common		*common;
}	t_philo;

//Set init state
int	save_info(t_info *dst, int argc, char **argv);
int	make_common_resource(t_common *rsc, t_info *info);
t_philo	*set_init_state(t_info *info, t_common *common);

//Philo_routine
void	*philo_routine(void *data);
int		philo_fork(t_philo *philo);
int		philo_eat(t_philo *philo);
int		philo_sleep(t_philo *philo);
int		philo_think(t_philo *philo);
int		philo_die(t_philo *philo);

//Logs
int		print_log(t_philo *philo, int runtime);
//Utils
int	ft_atoi(const char *nptr);
int	get_runtime(t_philo *philo, struct timeval start_time);

#endif
