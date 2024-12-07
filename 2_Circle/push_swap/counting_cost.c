/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:50:25 by takwak            #+#    #+#             */
/*   Updated: 2024/12/07 17:56:32 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	all_small_cost(t_ps *st, int a_rot, int b_rot)
{
	int	cnt;

	cnt = 0;
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

int	all_big_cost(t_ps *st, int a_rot, int b_rot)
{
	int	cnt;

	cnt = 0;
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

int	total_cost(int a_rot, int b_rot)
{
	int	cnt;

	cnt = 0;
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

int	find_cost(t_ps *st, int idx)
{
	int	b_rot;
	int	a_rot;

	a_rot = 0;
	b_rot = rotate_num(st->b_idx, idx);
	if (all_small(st->a, st->a_idx, st->b[idx]))
		return (all_small_cost(st, a_rot, b_rot));
	if (all_big(st->a, st->a_idx, st->b[idx]))
		return (all_big_cost(st, a_rot, b_rot));
	a_rot = count_a_rot(st, idx);
	return (total_cost(a_rot, b_rot));
}
