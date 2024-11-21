/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:46:17 by takwak            #+#    #+#             */
/*   Updated: 2024/11/21 13:43:46 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <libft.h>

typedef struct s_ps
{
	int	*a;
	int	*b;
	int	a_idx;
	int	b_idx;
}	t_ps;

void	data_load(t_ps *st, int argc, char **argv);
void	print_stack(t_ps *st);
void	ra(t_ps *st);
void	rb(t_ps *st);
void	rr(t_ps *st);
void	sa(t_ps *st);
void	sb(t_ps *st);
void	ss(t_ps *st);
void	pa(t_ps *st);
void	pb(t_ps *st);
void	rra(t_ps *st);
void	rrb(t_ps *st);
void	rrr(t_ps *st);
#endif
