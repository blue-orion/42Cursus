/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 02:05:40 by takwak            #+#    #+#             */
/*   Updated: 2024/12/29 04:39:18 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>

typedef enum e_status
{
	FINISH = 0,
	DIE,
	FORK,
	EAT,
	SLEEP,
	THINK
}	t_status;

typedef struct s_info
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_time;
	struct timeval	start_time;
}	t_info;

typedef struct s_common
{
	sem_t	*fork_sem;
	sem_t	*print_sem;
}	t_common;

typedef struct s_mutex
{
	pthread_mutex_t eat_cnt_mutex;
	pthread_mutex_t time_mutex;
	pthread_mutex_t status_mutex;
}	t_mutex;

typedef struct s_philo
{
	int				id;
	int				eat_cnt;
	t_status		status;
	struct timeval	cur_time;
	struct timeval	last_eat_time;
	pid_t			pid;
	pthread_t		tid;
	t_info			*info;
	t_common		*common;
	t_mutex			*mutex;
}	t_philo;

//Set initial state
int	save_info(t_info *info, int argc, char **argv);
int	make_common_resource(t_common *common, t_info info);
t_philo	*set_initial_state(t_info *info, t_common *common);

//Philo main
void	*monitoring(void *data);
void	start_behavior(t_philo *philo);
void	philo_main(t_philo *philo);

//Exit
int	error_exit(char *s, t_philo *philos);

//Philo Utils
void	set_status(t_philo *philo, t_status status);
//Utils
int	print_log(int runtime, int id, t_status status, sem_t *print_sem);
int	get_runtime(struct timeval cur, struct timeval start);
int	ft_atoi(const char *nptr);
#endif
