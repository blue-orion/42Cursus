/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:20:53 by takwak            #+#    #+#             */
/*   Updated: 2024/11/21 12:10:17 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *st)
{
	int	tmp;
	int	i;

	if (st->a_idx == 0)
		return ;
	i = 1;
	tmp = st->a[1];
	while (i < st->a_idx)
	{
		st->a[i] = st->a[i + 1];
		i++;
	}
	st->a[i] = tmp;
	ft_printf("ra\n");
}

void	rb(t_ps *st)
{
	int	tmp;
	int	i;

	if (st->b_idx == 0)
		return ;
	i = 1;
	tmp = st->b[1];
	while (i < st->b_idx)
	{
		st->b[i] = st->b[i + 1];
		i++;
	}
	st->b[i] = tmp;
	ft_printf("rb\n");
}

void	rr(t_ps *st)
{
	ra(st);
	rb(st);
	ft_printf("rr\n");
}
