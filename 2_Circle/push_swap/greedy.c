/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:36:31 by takwak            #+#    #+#             */
/*   Updated: 2024/11/26 03:31:23 by takwak           ###   ########.fr       */
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
		*cnt += ra(st);
	if (max_idx == 2)
		*cnt += rra(st);
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

void	div_part2_sort(t_ps *st, int *cnt)
{
	// int	div2;
	int	cnt_tmp;

	cnt_tmp = 0;
	// div2 = 2 * (st->size / 3);
	// while (st->b[st->b_idx] >= div2)
	while (st->b_idx > 0)
	{
		if (st->b_idx != 1 && st->b[st->b_idx] == st->size)
			rb(st);
		if (st->b_idx == 1 && st->b[st->b_idx] == st->size)
		{
			while (st->a[st->a_idx] != 1)
			{
				if (find_data(st->a, st->a_idx, 1) == 1)
					ra(st);
				else
					rra(st);
			}
			pa(st);
			ra(st);
			break ;
		}
		if (st->a[st->a_idx] < st->b[st->b_idx])
		{
			if (all_small(st->a, st->a_idx, st->b[st->b_idx]))
			{
				while (st->a[st->a_idx] != find_min(st->a, st->a_idx))
				{
					if (find_data(st->a, st->a_idx, find_min(st->a, st->a_idx)) == 1)
					{
						ra(st);
						print_stack(st);
					}
					else
					{
						rra(st);
						print_stack(st);
					}
				}
				pa(st);
				ra(st);
				continue ;
			}
			while (st->a[st->a_idx - 1] < st->b[st->b_idx])
			{
				*cnt += ra(st);
				print_stack(st);
			}
			pa(st);
			print_stack(st);
			sa(st);
			print_stack(st);
			continue ;
		}
		if (st->b[st->b_idx] < st->a[st->a_idx])
		{
			cnt_tmp = 1;
			while (st->a[cnt_tmp] > st->a[cnt_tmp + 1])
				cnt_tmp++;
			while (cnt_tmp > 0 && st->a[cnt_tmp] < st->b[st->b_idx])
					cnt_tmp--;
			while (cnt_tmp != st->a_idx && cnt_tmp != 0)
			{
				*cnt += rra(st);
				print_stack(st);
				cnt_tmp--;
			}
			pa(st);
			print_stack(st);
			continue ;
		}
	}
}

void	greedy_sort(t_ps *st, int *cnt)
{
	first_three_sort(st, cnt);
	print_stack(st);
	div_part2_sort(st, cnt);
	*cnt = *cnt;
	st->a[st->a_idx] = st->a[st->a_idx];
}
