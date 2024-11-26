/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:57:36 by takwak            #+#    #+#             */
/*   Updated: 2024/11/25 23:14:40 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_atob(t_ps *st, int digit, int *cnt)
{
	int	*temp;
	int	target;
	int	i;
	int	j;

	if (st->size / (digit / 10) == 1 && st->size % (digit / 10) == 0)
	{
		ra(st);
		return ;
	}
	if (st->size / (digit / 10) == 0)
		return ;
	temp = (int *)ft_calloc(10, sizeof(int));
	i = 1;
	while (i <= st->a_idx)
	{
		target = (st->a[i] % digit) / (digit / 10);
		temp[target]++;
		i++;
	}
	j = 0;
	while (j < 10 && st->a_idx > 0)
	{
		if (temp[j] == 0)
		{
			j++;
			while (digit > 100 && (st->a[st->a_idx] % (digit / 10)) / (digit / 100) != 0)
			{
				*cnt += ra(st);
				print_stack(st);
			}
			continue ;
		}
		target = (st->a[st->a_idx] % digit) / (digit / 10);
		if (temp[j] != 0 && target == j)
		{
			*cnt += pb(st);
			print_stack(st);
			temp[j]--;
		}
		else
		{
			*cnt += ra(st);
			print_stack(st);
		}
	}
	free(temp);
	radix_btoa(st, digit * 10, cnt);
}

void	radix_btoa(t_ps *st, int digit, int *cnt)
{
	int	*temp;
	int	target;
	int	i;
	int	j;

	if (st->size / (digit / 10) == 0)
	{
		while (st->b_idx > 0)
		{
			*cnt += pa(st);
			print_stack(st);
		}
		return ;
	}
	temp = (int *)ft_calloc(10 ,sizeof(int));
	i = 1;
	while (i <= st->b_idx)
	{
		target = (st->b[i] % digit) / (digit / 10);
		temp[target]++;
		i++;
	}
	j = 9;
	while (j >= 0 && st->b_idx > 0)
	{
		if (temp[j] == 0)
		{
			j--;
			while ((st->b[st->b_idx] % (digit / 10)) / (digit / 100) != 9)
			{
				*cnt += rb(st);
				print_stack(st);
			}
			continue ;
		}
		target = (st->b[st->b_idx] % digit) / (digit / 10);
		if (temp[j] != 0 && target == j)
		{
			*cnt += pa(st);
			print_stack(st);
			temp[j]--;
		}
		else
		{
			*cnt += rb(st);
			print_stack(st);
		}
	}
	free(temp);
	radix_atob(st, digit * 10, cnt);
}
