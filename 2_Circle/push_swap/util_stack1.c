/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:20:53 by takwak            #+#    #+#             */
/*   Updated: 2024/11/22 21:56:02 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_pslst *st)
{
	t_list	*past;
	t_list	*last;

	past = st->a;
	st->a = st->a->next;
	past->next = NULL;
	last = st->a;
	ft_lstlast(last);
	last->next = past;
	ft_printf("ra\n");
}

void	rb(t_pslst *st)
{
	t_list	*past;
	t_list	*last;

	past = st->b;
	st->b = st->b->next;
	past->next = NULL;
	last = st->b;
	ft_lstlast(last);
	last->next = past;
	ft_printf("rb\n");
}

void	rr(t_pslst *st)
{
	ra(st);
	rb(st);
	ft_printf("rr\n");
}
