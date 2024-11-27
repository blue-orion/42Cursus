/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:46:17 by takwak            #+#    #+#             */
/*   Updated: 2024/11/27 17:55:51 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <libft.h>
# include <stddef.h>

typedef struct s_ps
{
	int	*a;
	int	*b;
	int	a_idx;
	int	b_idx;
	int	size;
}	t_ps;

//Stack Command
int	ra(t_ps *st);
int	rb(t_ps *st);
int	rr(t_ps *st);
int	sa(t_ps *st);
int	sb(t_ps *st);
int	ss(t_ps *st);
int	pa(t_ps *st);
int	pb(t_ps *st);
int	rra(t_ps *st);
int	rrb(t_ps *st);
int	rrr(t_ps *st);

void	data_load(t_ps *st, int argc, char **argv);
void	print_stack(t_ps *st);
void	merge_sort(int *arr, int *sorted, int left, int right);
void	merge(int *arr, int *sorted, int left, int right);
void	indexing(t_ps *st);
void	radix_btoa(t_ps *st, int digit, int *cnt);
void	radix_atob(t_ps *st, int digit, int *cnt);
int		count_cmd(t_ps *st, char *cmd);
void	ft_reverse(int *st, int size);
void	greedy_sort(t_ps *st, int *cnt);
int		is_interval(int n, int *st, int a, int b);
int		is_sorted(int order, int *st, int size);
int		find_data(int *st, int size, int tofind);
int		find_min(int *st, int size);
void	divide(t_ps *st, int *cnt);

//BackTracking
void	user_ra(t_ps *st);
void	user_rb(t_ps *st);
void	user_rr(t_ps *st);
void	user_sa(t_ps *st);
void	user_sb(t_ps *st);
void	user_ss(t_ps *st);
void	user_pa(t_ps *st);
void	user_pb(t_ps *st);
void	user_rra(t_ps *st);
void	user_rrb(t_ps *st);
void	user_rrr(t_ps *st);

#endif
