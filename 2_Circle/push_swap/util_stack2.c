/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:43:29 by takwak            #+#    #+#             */
/*   Updated: 2024/11/23 18:21:38 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_ps *st)
{
	int	tmp;

	if (st->a_idx < 2)
		return (1);
	tmp = st->a[st->a_idx];
	st->a[st->a_idx] = st->a[st->a_idx - 1];
	st->a[st->a_idx - 1] = tmp;
	ft_printf("sa\n");
	return (1);
}

int	sb(t_ps *st)
{
	int	tmp;

	if (st->b_idx < 2)
		return (1);
	tmp = st->b[st->b_idx];
	st->b[st->b_idx] = st->b[st->b_idx - 1];
	st->b[st->b_idx - 1] = tmp;
	ft_printf("sb\n");
	return (1);
}

int	ss(t_ps *st)
{
	sa(st);
	sb(st);
	ft_printf("ss\n");
	return (1);
}

int	pa(t_ps *st)
{
	st->a[++(st->a_idx)] = st->b[st->b_idx];
	st->b[st->b_idx--] = 0;
	ft_printf("pa\n");
	return (1);
}

int	pb(t_ps *st)
{
	st->b[++(st->b_idx)] = st->a[st->a_idx];
	st->a[st->a_idx--] = 0;
	ft_printf("pb\n");
	return (1);
}
