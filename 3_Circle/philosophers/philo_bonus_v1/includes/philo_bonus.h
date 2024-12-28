/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:33:48 by takwak            #+#    #+#             */
/*   Updated: 2024/12/29 01:26:16 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>

enum s_status
{
	FORK = 1,
	EAT = 2,
	SLEEP = 3,
	THINK = 4,
	COMPLETE = 5,
	DIE = 6
};

typedef struct s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
}	t_info;

typedef struct s_common
{
	sem_t			*fork_sem;
	sem_t			*print_sem;
	struct timeval	start_time;
}	t_common;

typedef struct s_philo
{
	int				id;
	int				status;
	int				eat_cnt;
	int				having_fork_num;
	int				flag;
	struct timeval	cur_time;
	struct timeval	dead_time;
	struct timeval	last_eat_time;
	pid_t			pid;
	pthread_t		tid;
	pthread_mutex_t	*time_mutex;
	pthread_mutex_t	*flag_mutex;
	t_info			*info;
	t_common		*common;
}	t_philo;

//Philo act
int			check_dead(t_philo *philo);
void		*monitoring(void *data);
void		start_action(t_philo *philo);
int			get_runtime(struct timeval cur, struct timeval start);
int			philo_eat(t_philo *philo);
int			philo_think(t_philo *philo);
int			philo_sleep(t_philo *philo);
int			philo_take_fork(t_philo *philo);

//Print_log
int			print_log(t_philo *philo, int runtime);

//Monitoring
int			check_dead_flag(t_common *common);
int			is_meet_must_eat_cnt(t_philo *philo);
int			is_philo_dead(t_philo *philo);
int			wait_end_philo(t_philo *philos);

//Save info
t_info		*save_info(int argc, char **argv);
t_philo		*set_initial_state(int argc, char **argv);
int			make_common_source(t_common *common, t_info *info);

//Utils
int			ft_atoi(const char *nptr);
void		success_exit(t_philo *philos);
void		*free_common(t_common *common);
void		error_exit(void);
#endif
