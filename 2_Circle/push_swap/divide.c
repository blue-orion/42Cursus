/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:51:10 by takwak            #+#    #+#             */
/*   Updated: 2024/11/27 17:47:57 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		all_part3(t_ps *st, int div2)
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

void	divide(t_ps *st, int *cnt)
{
	int	div1;
	int	div2;

	div1 = st->a_idx / 3;
	div2 = 2 * (st->a_idx / 3);
	while (st->a[st->a_idx] >= div2)
	{
		// printf("div2 = %d\n", div2);
		*cnt += ra(st);
		print_stack(st);
	}
	pb(st);
	while (st->a_idx > 0)
	{
		if (st->a[st->a_idx] < div1)
		{
			*cnt += pb(st);
			*cnt += rb(st);
			print_stack(st);
			continue ;
		}
		if (st->a[st->a_idx] >= div1 && st->a[st->a_idx] < div2)
		{
			*cnt += pb(st);
			if (st->b[st->b_idx] < st->b[st->b_idx - 1])
				*cnt += sb(st);
			print_stack(st);
			continue ;
		}
		if (st->a[st->a_idx] >= div2)
		{
			if (all_part3(st, div2))
				break ;
			*cnt += ra(st);
			print_stack(st);
			continue ;
		}
	}
	while (st->a_idx > 3)
	{
		*cnt += pb(st);
		print_stack(st);
	}

}
