/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:46:17 by takwak            #+#    #+#             */
/*   Updated: 2024/12/06 23:31:40 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <libft.h>
# include <limits.h>

typedef struct s_ps
{
	int	*a;
	int	*b;
	int	a_idx;
	int	b_idx;
	int	size;
}	t_ps;

//Stack Command
int		ra(t_ps *st, int flag);
int		rb(t_ps *st, int flag);
int		rr(t_ps *st);
int		sa(t_ps *st);
int		sb(t_ps *st);
int		ss(t_ps *st);
int		pa(t_ps *st);
int		pb(t_ps *st);
int		rra(t_ps *st, int flag);
int		rrb(t_ps *st, int flag);
int		rrr(t_ps *st);

void	data_load(t_ps *st, int argc, char **argv);
int		validate_data (t_ps *st);
void	merge_sort(int *arr, int *sorted, int left, int right);
void	merge(int *arr, int *sorted, int left, int right);
void	indexing(t_ps *st);
void	ft_reverse(int *st, int size);
void	greedy_sort(t_ps *st, int *cnt);
int		is_interval(int n, int *st, int a, int b);
int		is_sorted(int order, int *st, int size);
int		find_data(int *st, int size, int tofind);
int		find_min(int *st, int size);
void	divide(t_ps *st, int *cnt);
void	greedy_two_sort(t_ps *st, int *cnt);
int		rotate_num(int size, int idx);
int		find_cost(t_ps *st, int idx);
int		total_cost(int a_rot, int b_rot);
int		count_a_rot(t_ps *st, int idx);
int		all_big_cost(t_ps *st, int a_rot, int b_rot);
int		all_small_cost(t_ps *st, int a_rot, int b_rot);
void	push_a(t_ps *st, int idx, int *cnt);
int		find_min_instruction(t_ps *st);
void	first_three_sort(t_ps *st, int *cnt);
int		find_big_than(int *st, int size, int compare);
int		find_small_than(int *st, int size, int compare);
int		ft_abs(int n);
int		all_small(int *st, int size, int comp);
int		all_big(int *st, int size, int comp);
int		find_min_idx(int *st, int size);
void	*free_twoptr(void **ptr, int size);
void	find_push_locate(t_ps *st, int a_rot, int b_rot, int *cnt);
void	edge_case_push(t_ps *st, int idx, int *cnt);
int		free_stack(t_ps *st);
void	get_first(t_ps *st, int *cnt);

void	print_stack(int *st, int size);
#endif
