/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:20:53 by takwak            #+#    #+#             */
/*   Updated: 2024/12/07 19:18:09 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_ps *st, int flag)
{
	int	tmp;
	int	i;

	if (st->a_idx == 0)
		return (1);
	i = st->a_idx;
	tmp = st->a[st->a_idx];
	while (i > 1)
	{
		st->a[i] = st->a[i - 1];
		i--;
	}
	st->a[1] = tmp;
	if (flag)
		ft_printf("ra\n");
	return (1);
}

int	rb(t_ps *st, int flag)
{
	int	tmp;
	int	i;

	if (st->b_idx == 0)
		return (1);
	i = st->b_idx;
	tmp = st->b[st->b_idx];
	while (i > 1)
	{
		st->b[i] = st->b[i - 1];
		i--;
	}
	st->b[1] = tmp;
	if (flag)
		ft_printf("rb\n");
	return (1);
}

int	rr(t_ps *st, int flag)
{
	ra(st, 0);
	rb(st, 0);
	if (flag)
		ft_printf("rr\n");
	return (1);
}
