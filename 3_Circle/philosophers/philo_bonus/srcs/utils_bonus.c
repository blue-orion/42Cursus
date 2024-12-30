/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:59:06 by takwak            #+#    #+#             */
/*   Updated: 2024/12/29 19:59:14 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

char	*make_sema_name(char *sem_name, int num)
{
	char	*res;
	int		len;
	int		i;

	len = 0;
	while (sem_name[len])
		len++;
	res = (char *)malloc(sizeof(char) * (len + 4));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = sem_name[i];
		i++;
	}
	while (num != 0)
	{
		res[i] = num % 10 + '0';
		num /= 10;
		i++;
	}
	res[i] = '\0';
	return (res);
}

sem_t	*open_semaphore(char *name, int value)
{
	sem_t	*dst;

	dst = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (!dst)
	{
		sem_unlink(name);
		dst = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	}
	return (dst);
}

int	error_exit(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}
