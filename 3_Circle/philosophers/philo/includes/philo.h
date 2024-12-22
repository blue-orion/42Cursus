/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:18:54 by takwak            #+#    #+#             */
/*   Updated: 2024/12/23 01:52:50 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef enum c_status
{
	FORK,
	EAT,
	SLEEP,
	DIE,
	THINK
}	t_status;

typedef struct s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				have_to_eat;
	struct timeval	start_time;
	int				*fork;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	print_mutex;
	int				eat_finish;
	int				end_flag;
	pthread_mutex_t	end_flag_mutex;
}	t_info;

typedef struct s_philo
{
	t_info			*info;
	pthread_t		tid;
	int				num;
	struct timeval	last_eat_time;
	struct timeval	cur_time;
	int				status;
	int				left_fork;
	int				right_fork;
	int				eat_num;
}	t_philo;

//Philo Behavior
int		philo_eat(t_philo *philo);
int		philo_sleep(t_philo *philo);
int		philo_think(t_philo *philo);
int		have_to_die(t_philo *philo);

//Fork
int		pick_up_left_fork(t_philo *philo);
int		pick_up_right_fork(t_philo *philo);
int		put_down_left_fork(t_philo *philo);
int		put_down_right_fork(t_philo *philo);

//Monitoring.c
int		monitoring(t_philo *philos);
int		print_timestamp(struct timeval *tv);
int		print_log(t_philo *philo, long cur_time);
int		check_dead_flag(t_philo *philo);

//Timestamp.c
long	get_current_time(struct timeval *cur, struct timeval *start);

//Make_thread.c
void	*thread_main(void *cnt);
t_philo	*make_philo(t_info *info);

//Utils
t_info	*save_info(char **argv);
int		ft_atoi(const char *nptr);
void	error_in_print_mutex_making(t_info *info);
void	error_in_fork_making(t_info *info, int success_num);
void	error_in_make_threads(t_info *info, t_philo *philo, int success_num);
void	free_info(t_info *info);
void	end_process(t_info *info, t_philo *philos);
#endif
