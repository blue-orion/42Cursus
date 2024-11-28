/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_greedy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:03:58 by takwak            #+#    #+#             */
/*   Updated: 2024/11/27 19:06:52 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_num(int size, int idx)
{
	int	num;

	if (idx >= size / 2)
		num = size - idx;
	else
		num = -1 * idx;
	return (num);
}

int	find_cost(t_ps *st, int idx)
{
	int	b_rot;
	int	a_rot;
	int	cnt;

	cnt = 0;
	b_rot = rotate_num(st->b_idx, idx);
	if (all_small(st->a, st->a_idx, st->b[idx]))
	{
		a_rot = find_min_idx(st->a, st->a_idx);
		if (a_rot == st->a_idx)
			a_rot = 0;
		a_rot = rotate_num(st->a_idx, a_rot);
		while (a_rot > 0 && b_rot > 0)
		{
			cnt++;
			a_rot--;
			b_rot--;
		}
		while (a_rot < 0 && b_rot < 0)
		{
			cnt++;
			a_rot++;
			b_rot++;
		}
		return (cnt + ft_abs(a_rot) + ft_abs(b_rot) + 1);
	}
	if (all_big(st->a, st->a_idx, st->b[idx]))
	{
		a_rot = find_min_idx(st->a, st->a_idx);
		if (a_rot == st->a_idx)
			a_rot = 0;
		a_rot = rotate_num(st->a_idx, a_rot);
		while (a_rot > 0 && b_rot > 0)
		{
			cnt++;
			a_rot--;
			b_rot--;
		}
		while (a_rot < 0 && b_rot < 0)
		{
			cnt++;
			a_rot++;
			b_rot++;
		}
		return (cnt + ft_abs(a_rot) + ft_abs(b_rot));
	}
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
	if (a_rot > st->a_idx / 2)
		a_rot = st->a_idx - a_rot;
	else
		a_rot *= -1;
	while (a_rot > 0 && b_rot > 0)
	{
		cnt++;
		a_rot--;
		b_rot--;
	}
	while (a_rot < 0 && b_rot < 0)
	{
		cnt++;
		a_rot++;
		b_rot++;
	}
	cnt += ft_abs(a_rot) + ft_abs(b_rot);
	return (cnt);
}

void	find_push_locate(t_ps *st, int a_rot, int b_rot, int *cnt)
{
	while (a_rot > 0 && b_rot > 0)
	{
		*cnt += rr(st);
		a_rot--;
		b_rot--;
	}
	while (a_rot < 0 && b_rot < 0)
	{
		*cnt += rrr(st);
		a_rot++;
		b_rot++;
	}
	while (a_rot != 0 || b_rot != 0)
	{
		if (a_rot > 0)
		{
			*cnt += ra(st, 1);
			a_rot--;
		}
		if (a_rot < 0)
		{
			*cnt += rra(st, 1);
			a_rot++;
		}
		if (b_rot > 0)
		{
			*cnt += rb(st, 1);
			b_rot--;
		}
		if (b_rot < 0)
		{
			*cnt += rrb(st, 1);
			b_rot++;
		}
	}
}

void	push_a(t_ps *st, int idx, int *cnt)
{
	int	b_rot;
	int	a_rot;

	b_rot = rotate_num(st->b_idx, idx);
	if (all_small(st->a, st->a_idx, st->b[idx]))
	{
		a_rot = find_min_idx(st->a, st->a_idx);
		if (a_rot == st->a_idx)
			a_rot = 0;
		a_rot = rotate_num(st->a_idx, a_rot);
		find_push_locate(st, a_rot, b_rot, cnt);
		*cnt += pa(st);
		*cnt += ra(st, 1);
		return ;
	}
	if (all_big(st->a, st->a_idx, st->b[idx]))
	{
		a_rot = find_min_idx(st->a, st->a_idx);
		if (a_rot == st->a_idx)
			a_rot = 0;
		a_rot = rotate_num(st->a_idx, a_rot);
		find_push_locate(st, a_rot, b_rot, cnt);
		*cnt += pa(st);
		return ;
	}
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
	find_push_locate(st, a_rot, b_rot, cnt);
	*cnt += pa(st);
	return ;
}

int	find_min_instruction(t_ps *st)
{
	int	*cost;
	int	min_idx;
	int	idx;

	min_idx = st->b_idx;
	idx = st->b_idx;
	cost = (int *)malloc(sizeof(int) * (st->b_idx + 1));
	cost[min_idx] = find_cost(st, idx--);
	while (idx > 0)
	{
		cost[idx] = find_cost(st, idx);
		if (ft_abs(cost[idx]) <= ft_abs(cost[min_idx]))
			min_idx = idx;
		idx--;
	}
	free(cost);
	return (min_idx);
}

void	get_first(t_ps *st, int *cnt)
{
	int	idx;

	idx = find_data(st->a, st->a_idx, 1);
	while (idx > 0)
	{
		*cnt += ra(st, 1);
		idx--;
	}
	while (idx < 0)
	{
		*cnt += rra(st, 1);
		idx++;
	}
}

void	greedy_two_sort(t_ps *st, int *cnt)
{
	int	bi;

	first_three_sort(st, cnt);
	while (st->b_idx > 0)
	{
		bi = find_min_instruction(st);
		push_a(st, bi, cnt);
	}
	get_first(st, cnt);
}
