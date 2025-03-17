/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:19:58 by takwak            #+#    #+#             */
/*   Updated: 2025/03/17 17:15:41 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <limits.h>

int	is_digit_str(char *s);
int	is_digit(char c);

int	ft_philo_atoi(char *s)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '+')
		i++;
	if (!is_digit_str(s + i))
		return (-1);
	while (s[i])
	{
		num = num * 10 + s[i] - '0';
		i++;
	}
	if (num > INT_MAX || num < 0)
		return (-1);
	return ((int)num);
}

int	is_digit_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!is_digit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
