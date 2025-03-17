/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:32:17 by takwak            #+#    #+#             */
/*   Updated: 2025/03/17 21:46:34 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*ft_sem_open(char *name, int value)
{
	sem_t	*new;

	new = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (!new)
	{
		sem_unlink(name);
		new = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	}
	if (!new)
		return (NULL);
	return (new);
}

void	ft_sem_destroy(sem_t *sem, char *name)
{
	sem_close(sem);
	sem_unlink(name);
}

int	get_value(t_sema *sem)
{
	int	value;

	sem_wait(sem->lock);
	value = *(sem->value);
	sem_post(sem->lock);
	return (value);
}

void	set_value(t_sema *sem, int value)
{
	sem_wait(sem->lock);
	*sem->value = value;
	sem_post(sem->lock);
}
