/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:51:01 by takwak            #+#    #+#             */
/*   Updated: 2024/12/29 23:34:05 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	philo_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	philo_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

int	philo_atoi(const char *nptr)
{
	int	res;
	int	fl;

	res = 0;
	fl = 1;
	while (philo_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			fl *= -1;
		nptr++;
	}
	while (philo_isdigit(*nptr) && *nptr != '\0')
	{
		if (res > (INT_MAX - (*nptr - '0')) / 10)
			return (0);
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (fl * res);
}
