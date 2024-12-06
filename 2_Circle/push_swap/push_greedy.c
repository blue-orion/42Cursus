/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_greedy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:03:58 by takwak            #+#    #+#             */
/*   Updated: 2024/12/06 22:38:38 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_ps *st, int idx, int *cnt)
{
	int	b_rot;
	int	a_rot;

	if (all_small(st->a, st->a_idx, st->b[idx])
		|| all_big(st->a, st->a_idx, st->b[idx]))
		return (edge_case_push(st, idx, cnt));
	a_rot = count_a_rot(st, idx);
	b_rot = rotate_num(st->b_idx, idx);
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
