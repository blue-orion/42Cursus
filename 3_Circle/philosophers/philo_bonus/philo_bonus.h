/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:19:21 by takwak            #+#    #+#             */
/*   Updated: 2025/03/19 16:52:02 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <fcntl.h>
# include <string.h>

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

typedef struct s_common
{
	sem_t	*print;
	sem_t	*fork;
}	t_common;

typedef struct s_philo
{
	pid_t			pid;
	int				id;
	int				eat_cnt;
	struct timeval	last_eat_time;
	int				died;
	t_info			*info;
	t_common		*common;
}	t_philo;

//Main
int		save_info(t_info *info, int ac, char **av);
int		make_common(t_info *info, t_common *common);
t_philo	*make_philos(t_philo *philo, t_info *info, t_common *common);
void	monitoring(t_philo *philo);

//Utils
int		ft_philo_atoi(char *s);
void	ft_usleep(t_philo *philo, int time);
int		get_runtime(struct timeval start);
void	print_log(t_philo *philo, int time, int status);
char	*make_sema_name(char *dst, char *src, int num);

//Semaphore
sem_t	*ft_sem_open(char *name, int value);
void	ft_sem_destroy(sem_t *sem, char *name);

//Philo routine
void	philo_routine(t_philo *philos, int id);
void	philo_fork(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
int		have_to_stop(t_philo *philo);
#endif
