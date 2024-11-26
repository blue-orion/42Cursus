/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:24:30 by takwak            #+#    #+#             */
/*   Updated: 2024/11/25 22:52:40 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_ps *st)
{
	int	tmp;
	int	i;

	if (st->a_idx == 0)
		return (1);
	i = 1;
	tmp = st->a[1];
	while (i < st->a_idx)
	{
		st->a[i] = st->a[i + 1];
		i++;
	}
	st->a[st->a_idx] = tmp;
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_ps *st)
{
	int	tmp;
	int	i;

	if (st->b_idx == 0)
		return (1);
	i = 1;
	tmp = st->b[1];
	while (i < st->b_idx)
	{
		st->b[i] = st->b[i + 1];
		i++;
	}
	st->b[st->b_idx] = tmp;
	ft_printf("rrb\n");
	return (1);
}

int	rrr(t_ps *st)
{
	rra(st);
	rrb(st);
	ft_printf("rrb\n");
	return (1);
}
