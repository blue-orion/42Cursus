/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:30:50 by takwak            #+#    #+#             */
/*   Updated: 2024/12/08 01:36:17 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n > 0)
		return (n);
	else
		return (-1 * n);
}

void	*free_twoptr(void **ptr, int size)
{
	int	i;

	i = 0;
	if (ptr == NULL)
		return (NULL);
	while (i < size)
		free(ptr[i++]);
	free(ptr);
	return (NULL);
}

int	is_sorted(int *st, int size)
{
	int	i;

	i = size;
	while (i > 1)
	{
		if (st[i] < st[i - 1])
			i--;
		else
			return (0);
	}
	return (1);
}

int	str_isdigit(char *s)
{
	while (*s)
	{
		if (*s == '+' || *s == '-')
		{
			s++;
			continue ;
		}
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

long long	ft_atoll(char *nptr)
{
	long long	res;
	int			fl;

	res = 0;
	fl = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			fl *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr) && *nptr != '\0')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (fl * res);
}
