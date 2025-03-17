/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 02:05:40 by takwak            #+#    #+#             */
/*   Updated: 2025/03/17 17:15:56 by takwak           ###   ########.fr       */
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
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_time;
	struct timeval	start_time;
	pid_t			*pid;
}	t_info;

typedef struct s_name_sem
{
	sem_t	*adr;
	char	*name;
}	t_sem;

typedef struct s_common
{
	t_sem	*fork_sem;
	t_sem	*print_sem;
}	t_common;

typedef struct s_philo
{
	int				id;
	t_status		status;
	int				eat_cnt;
	t_sem			*eat_cnt_sem;
	int				flag;
	t_sem			*flag_sem;
	struct timeval	cur_time;
	struct timeval	last_eat_time;
	t_sem			*time_sem;
	pthread_t		tid;
	t_info			*info;
	t_common		*common;
}	t_philo;

//Main
void	wait_childs(t_info *info);
void	free_resources(t_info *info, t_common *common);

//Set initial state
int		save_info(t_info *info, int argc, char **argv);
int		make_common_resource(t_common *common, t_info info);
int		set_initial_state(t_info *info, t_common *common);

//Philo main
void	philo_main(t_philo *philo);
void	start_behavior(t_philo *philo);
int		philo_take_fork(t_philo *philo);
int		philo_eat(t_philo *philo);
int		philo_sleep(t_philo *philo);
int		philo_think(t_philo *philo);

//Philo monitoring
void	*monitoring(void *data);
int		is_philo_dead(t_philo *philo);
int		is_philo_eat_finish(t_philo *philo);

//Exit
int		error_exit(char *s);

//Philo Utils
int		end_process(t_philo *philo);
int		is_iam_end(t_philo *philo);
void	free_philo_resource(t_philo *philo);

//Utils
int		print_log(int runtime, t_philo *philo);
int		get_runtime(t_philo *philo, struct timeval start_time);
int		ft_philo_atoi(char *s);
sem_t	*open_semaphore(char *name, int value);
char	*make_sema_name(char *sem_name, int num);

#endif
