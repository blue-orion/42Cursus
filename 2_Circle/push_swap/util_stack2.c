/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:43:29 by takwak            #+#    #+#             */
/*   Updated: 2024/12/07 20:01:00 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_ps *st, int flag)
{
	int	tmp;

	if (st->a_idx < 2)
		return (1);
	tmp = st->a[st->a_idx];
	st->a[st->a_idx] = st->a[st->a_idx - 1];
	st->a[st->a_idx - 1] = tmp;
	if (flag)
		ft_printf("sa\n");
	return (1);
}

int	sb(t_ps *st, int flag)
{
	int	tmp;

	if (st->b_idx < 2)
		return (1);
	tmp = st->b[st->b_idx];
	st->b[st->b_idx] = st->b[st->b_idx - 1];
	st->b[st->b_idx - 1] = tmp;
	if (flag)
		ft_printf("sb\n");
	return (1);
}

int	ss(t_ps *st, int flag)
{
	sa(st, 0);
	sb(st, 0);
	if (flag)
		ft_printf("ss\n");
	return (1);
}

int	pa(t_ps *st, int flag)
{
	if (st->b_idx == 0)
		return (1);
	st->a[++(st->a_idx)] = st->b[st->b_idx];
	st->b[st->b_idx--] = 0;
	if (flag)
		ft_printf("pa\n");
	return (1);
}

int	pb(t_ps *st, int flag)
{
	if (st->a_idx == 0)
		return (1);
	st->b[++(st->b_idx)] = st->a[st->a_idx];
	st->a[st->a_idx--] = 0;
	if (flag)
		ft_printf("pb\n");
	return (1);
}
