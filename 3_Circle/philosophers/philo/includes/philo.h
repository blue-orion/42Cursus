/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:18:54 by takwak            #+#    #+#             */
/*   Updated: 2024/12/21 03:57:10 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

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
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	min_eating_num;
	struct timeval	start_time;
}	t_info;

typedef struct s_philo
{
	pthread_t	tid;
	int	num;
	struct timeval	start_time;
	struct timeval	last_eat_time;
	struct timeval	cur_time;
	int	status;
	int	left_fork;
	int	right_fork;
	int	sleep;
	int	think;
}	t_philo;

int	print_timestamp(struct timeval *tv);
int	print_log(int num, struct timeval tv, int status);

//Timestamp.c
int	get_current_time(struct timeval *cur, struct timeval *start);

//Make_thread.c
void	*new_philo(void *cnt);
t_philo	*make_philo(t_info *info);
int	make_thread(t_info *info);
t_info	*save_info(char **argv);
int	ft_atoi(const char *nptr);
#endif
