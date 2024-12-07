/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:25:39 by takwak            #+#    #+#             */
/*   Updated: 2024/12/07 19:22:00 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotating(t_ps *st, int a_rot, int b_rot, int *cnt)
{
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

void	find_push_locate(t_ps *st, int a_rot, int b_rot, int *cnt)
{
	while (a_rot > 0 && b_rot > 0)
	{
		*cnt += rr(st, 1);
		a_rot--;
		b_rot--;
	}
	while (a_rot < 0 && b_rot < 0)
	{
		*cnt += rrr(st, 1);
		a_rot++;
		b_rot++;
	}
	rotating(st, a_rot, b_rot, cnt);
}

void	edge_case_push(t_ps *st, int idx, int *cnt)
{
	int	a_rot;
	int	b_rot;

	a_rot = find_min_idx(st->a, st->a_idx);
	b_rot = rotate_num(st->b_idx, idx);
	if (a_rot == st->a_idx)
		a_rot = 0;
	a_rot = rotate_num(st->a_idx, a_rot);
	find_push_locate(st, a_rot, b_rot, cnt);
	*cnt += pa(st, 1);
	if (all_small(st->a, st->a_idx, st->b[idx]))
		*cnt += ra(st, 1);
	return ;
}

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
	*cnt += pa(st, 1);
	return ;
}
