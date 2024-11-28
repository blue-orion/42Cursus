/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:36:31 by takwak            #+#    #+#             */
/*   Updated: 2024/11/26 21:02:50 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_three_sort(t_ps *st, int *cnt)
{
	int	max;
	int	max_idx;
	int	i;

	max = st->a[1];
	max_idx = 1;
	i = 2;
	while (i <= 3)
	{
		if (st->a[i] > max)
		{
			max = st->a[i];
			max_idx = i;
		}
		i++;
	}
	if (max_idx == 3)
		*cnt += ra(st, 1);
	if (max_idx == 2)
		*cnt += rra(st, 1);
	if (st->a[3] > st->a[2])
		*cnt += sa(st);
}

int	all_small(int *st, int size, int comp)
{
	int	i;

	i = 1;
	while (i <= size)
	{
		if (st[i] > comp)
			return (0);
		i++;
	}
	return (1);
}

int	all_big(int *st, int size, int comp)
{
	int	i;

	i = 1;
	while (i <= size)
	{
		if (st[i] < comp)
			return (0);
		i++;
	}
	return (1);
}
