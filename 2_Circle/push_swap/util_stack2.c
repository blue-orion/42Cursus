/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:43:29 by takwak            #+#    #+#             */
/*   Updated: 2024/11/22 21:54:30 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_pslst *st)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = st->a;
	b = st->a->next;
	c = st->a->next->next;

	b->next = a;
	a->next = c;
	ft_printf("sa\n");
}

// void	sb(t_ps *st)
// {
// 	int	tmp;
//
// 	if (st->b_idx < 2)
// 		return ;
// 	tmp = st->b[st->b_idx];
// 	st->b[st->b_idx] = st->b[st->b_idx - 1];
// 	st->b[st->b_idx - 1] = tmp;
// 	ft_printf("sb\n");
// }
//
// void	ss(t_ps *st)
// {
// 	sa(st);
// 	sb(st);
// 	ft_printf("ss\n");
// }
//
// void	pa(t_ps *st)
// {
// 	st->a[++(st->a_idx)] = st->b[st->b_idx];
// 	st->b[st->b_idx--] = 0;
// 	ft_printf("pa\n");
// }
//
// void	pb(t_ps *st)
// {
// 	st->b[++(st->b_idx)] = st->a[st->a_idx];
// 	st->a[st->a_idx--] = 0;
// 	ft_printf("pb\n");
// }
