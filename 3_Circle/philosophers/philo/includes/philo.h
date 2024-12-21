/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:18:54 by takwak            #+#    #+#             */
/*   Updated: 2024/12/22 02:18:10 by takwak           ###   ########.fr       */
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
	pthread_mutex_t	*mutex;
	pthread_mutex_t	print_mutex;
	int				end;
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
int		print_timestamp(struct timeval *tv);
int		print_log(int num, long cur_time, int status, pthread_mutex_t *mutex);

//Timestamp.c
long	get_current_time(struct timeval *cur, struct timeval *start);

//Make_thread.c
void	*new_philo(void *cnt);
t_philo	*make_philo(t_info *info);
int		make_thread(t_info *info);
t_info	*save_info(char **argv);
int		ft_atoi(const char *nptr);

#endif
