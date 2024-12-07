/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:03:58 by takwak            #+#    #+#             */
/*   Updated: 2024/12/07 19:22:39 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	greedy_sort(t_ps *st, int *cnt)
{
	int	bi;
	int	size;

	size = st->size;
	if (size <= 5)
	{
		while (size > 3)
		{
			*cnt += pb(st, 1);
			size--;
		}
	}
	else
		divide(st, cnt);
	first_three_sort(st, cnt);
	while (st->b_idx > 0)
	{
		bi = find_min_instruction(st);
		push_a(st, bi, cnt);
	}
	get_first(st, cnt);
}
