/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:46:17 by takwak            #+#    #+#             */
/*   Updated: 2024/12/08 01:31:16 by takwak           ###   ########.fr       */
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
int			ra(t_ps *st, int flag);
int			rb(t_ps *st, int flag);
int			rr(t_ps *st, int flag);
int			sa(t_ps *st, int flag);
int			sb(t_ps *st, int flag);
int			ss(t_ps *st, int flag);
int			pa(t_ps *st, int flag);
int			pb(t_ps *st, int flag);
int			rra(t_ps *st, int flag);
int			rrb(t_ps *st, int flag);
int			rrr(t_ps *st, int flag);

//Data
void		data_load(t_ps *st, int argc, char **argv);
int			validate_data(t_ps *st);
void		ft_reverse(int *st, int size);

//Indexing
void		merge_sort(int *arr, int *sorted, int left, int right);
void		merge(int *arr, int *sorted, int left, int right);
void		indexing(t_ps *st);
//Greedy
void		greedy_sort(t_ps *st, int *cnt);
void		divide(t_ps *st, int *cnt);
void		first_three_sort(t_ps *st, int *cnt);
void		get_first(t_ps *st, int *cnt);

//Greedy Cost
int			find_cost(t_ps *st, int idx);
int			total_cost(int a_rot, int b_rot);
int			all_big_cost(t_ps *st, int a_rot, int b_rot);
int			all_small_cost(t_ps *st, int a_rot, int b_rot);

//Find, Rotate, Greedy Utils
int			find_data(int *st, int size, int tofind);
int			find_min(int *st, int size);
int			find_min_instruction(t_ps *st);
int			find_big_than(int *st, int size, int compare);
int			find_small_than(int *st, int size, int compare);
int			find_min_idx(int *st, int size);
int			rotate_num(int size, int idx);
int			all_small(int *st, int size, int comp);
int			all_big(int *st, int size, int comp);
int			count_a_rot(t_ps *st, int idx);

//Push Utils
void		find_push_locate(t_ps *st, int a_rot, int b_rot, int *cnt);
void		edge_case_push(t_ps *st, int idx, int *cnt);
void		push_a(t_ps *st, int idx, int *cnt);

//Utils and Debugging
int			ft_abs(int n);
int			ft_isspace(char c);
void		init_stack(t_ps *st);
void		*free_twoptr(void **ptr, int size);
int			free_stack(t_ps *st);
int			ft_exit(t_ps *st, int *tmp);
int			is_sorted(int *st, int size);
void		print_stack(int *st, int size);
int			str_isdigit(char *s);
long long	ft_atoll(char *nptr);
#endif
