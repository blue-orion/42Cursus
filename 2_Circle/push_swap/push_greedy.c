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
		num = size - idx; //rb()
	else
		num = -1 * idx; //rrb()
	return (num);
}

int	find_cost(t_ps *st, int idx)
{
	int	b_rot;
	int	a_rot;
	int	cnt;

	b_rot = rotate_num(st->b_idx, idx);
	if (all_small(st->a, st->a_idx, st-b[idx]))
		return (b_rot + 1);
	if (all_big(st->a, st->a_idx, st->b[idx]))
		return (b_rot);
	if (st->b[idx] > st->a[st->a_idx])
	{
		a_rot = find_big_than(st->a, st->a_idx, st->b[idx]);
		while (a_rot > 0 && b_rot > 0)
		{
			cnt++; //rr();
			a_rot--;
			b_rot--;
		}
	}
	if (st->b[idx] < st->a[st->a_idx])
	{
		a_rot = 1;
		while (st->a[a_rot] < st->b[idx])
			a_rot++;
		if (st->a[a_rot] < st->a[st->a_idx])
			a_rot *= -1;
	}
	while (a_rot < 0 && b_rot < 0)
	{
		cnt++; //rrr();
		a_rot++;
		b_rot++;
	}
	cnt += ft_abs(a_rot) + ft_abs(b_rot); //ra,rra or rb, rrb
	return (cnt); //나가서 pa();
}

int	find_min_instruction(t_ps *st)
{
	int	*cost;
	int	min_idx;
	int	idx;

	min_idx = st->b_idx;
	idx = st->b_idx;
	cost[min_idx] = find_cost(st, idx--);
	cost = (int *)malloc(sizeof(int) * st->b_idx);
	while (idx > 0)
	{
		cost[idx] = find_cost(st, idx);
		if (cost[idx] < cost[min_idx])
			min_idx = idx;
		idx++;
	}
	//Debugging
	for (int i = st->b_idx; i > 0; i--)
		printf("cost = %d\n", cost[i]);
	printf("min cost = %d\n", cost[min_idx]);
	free(cost);
	return (min_idx);
}

void	push_a(t_ps *st, int bi, int *cnt)
{

}
void	greedy_two_sort(t_ps *st, int *cnt)
{
	int	bi;

	first_three_sort(st, cnt);
	print_stack(st);
	bi = find_min_instruction(st);
	push_a(st, bi, cnt);
}
