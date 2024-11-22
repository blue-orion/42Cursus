/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:46:17 by takwak            #+#    #+#             */
/*   Updated: 2024/11/22 21:54:53 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <libft.h>

typedef struct s_pslst
{
	t_list	*a;
	t_list	*b;
}	t_pslst;

void	data_load(t_pslst *st, int argc, char **argv);
void	print_stack(t_pslst *st);
void	ra(t_pslst *st);
void	rb(t_pslst *st);
void	rr(t_pslst *st);
void	sa(t_pslst *st);
/*void	sb(t_ps *st);*/
/*void	ss(t_ps *st);*/
/*void	pa(t_ps *st);*/
/*void	pb(t_ps *st);*/
/*void	rra(t_ps *st);*/
/*void	rrb(t_ps *st);*/
/*void	rrr(t_ps *st);*/
#endif
