/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:51:10 by takwak            #+#    #+#             */
/*   Updated: 2024/12/06 17:02:40 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	all_part3(t_ps *st, int div2)
{
	int	i;

	i = 1;
	while (i <= st->a_idx)
	{
		if (st->a[i] < div2)
			return (0);
		i++;
	}
	return (1);
}

void	push_b(t_ps *st, int *cnt, int div1, int div2)
{
	if (st->a[st->a_idx] < div1)
	{
		*cnt += pb(st);
		*cnt += rb(st, 1);
		return ;
	}
	if (st->a[st->a_idx] >= div1 && st->a[st->a_idx] < div2)
	{
		*cnt += pb(st);
		if (st->b[st->b_idx] < st->b[st->b_idx - 1])
			*cnt += sb(st);
		return ;
	}
	if (st->a[st->a_idx] >= div2)
	{
		*cnt += ra(st, 1);
		return ;
	}
}

void	divide(t_ps *st, int *cnt)
{
	int	div1;
	int	div2;

	div1 = st->a_idx / 3;
	div2 = 2 * (st->a_idx / 3);
	while (st->a[st->a_idx] >= div2)
		*cnt += ra(st, 1);
	*cnt += pb(st);
	while (st->a_idx > 0)
	{
		if (all_part3(st, div2))
			break ;
		push_b(st, cnt, div1, div2);
	}
	while (st->a_idx > 3)
		*cnt += pb(st);
}
