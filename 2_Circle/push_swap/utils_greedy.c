/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_greedy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:36:31 by takwak            #+#    #+#             */
/*   Updated: 2024/12/07 19:21:44 by takwak           ###   ########.fr       */
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
		*cnt += sa(st, 1);
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

int	rotate_num(int size, int idx)
{
	int	num;

	if (idx >= size / 2)
		num = size - idx;
	else
		num = -1 * idx;
	return (num);
}

int	count_a_rot(t_ps *st, int idx)
{
	int	a_rot;

	a_rot = 0;
	if (st->b[idx] > st->a[st->a_idx])
	{
		a_rot = st->a_idx;
		while (st->a[a_rot] < st->b[idx])
			a_rot--;
	}
	if (st->b[idx] < st->a[st->a_idx])
	{
		a_rot = 1;
		while (st->a[a_rot] > st->b[idx] && st->a[a_rot + 1] > st->b[idx])
		{
			if (st->a[a_rot] < st->a[a_rot + 1])
				break ;
			a_rot++;
		}
		if (st->a[a_rot] < st->b[idx])
			a_rot = 0;
	}
	a_rot = rotate_num(st->a_idx, a_rot);
	return (a_rot);
}
