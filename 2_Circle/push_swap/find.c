/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:21:48 by takwak            #+#    #+#             */
/*   Updated: 2024/11/26 03:28:30 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int *st, int size)
{
	int	i;
	int	min;

	i = 1;
	min = 2147483647;
	while (i <= size)
	{
		if (st[i] < min)
			min = st[i];
		i++;
	}
	return (min);
}

int	find_data(int *st, int size, int tofind)
{
	int	i;
	int	find;

	i = 1;
	find = 0;
	while (i <= size)
	{
		if (st[i] == tofind)
			find = i;
		i++;
	}
	if (find > size / 2)
		return (1);
	else
		return (-1);
}
