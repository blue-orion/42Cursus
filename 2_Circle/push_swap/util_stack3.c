/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:24:30 by takwak            #+#    #+#             */
/*   Updated: 2024/11/22 21:54:42 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	rra(t_ps *st)
// {
// 	int	tmp;
// 	int	i;
//
// 	if (st->a_idx == 0)
// 		return ;
// 	i = st->a_idx;
// 	tmp = st->a[st->a_idx];
// 	while (i > 1)
// 	{
// 		st->a[i] = st->a[i - 1];
// 		i--;
// 	}
// 	st->a[i] = tmp;
// 	ft_printf("rra\n");
// }
//
// void	rrb(t_ps *st)
// {
// 	int	tmp;
// 	int	i;
//
// 	if (st->b_idx == 0)
// 		return ;
// 	i = st->b_idx;
// 	tmp = st->b[st->b_idx];
// 	while (i > 1)
// 	{
// 		st->b[i] = st->b[i - 1];
// 		i--;
// 	}
// 	st->b[i] = tmp;
// 	ft_printf("rrb\n");
// }
//
// void	rrr(t_ps *st)
// {
// 	rra(st);
// 	rrb(st);
// 	ft_printf("rrb\n");
// }
