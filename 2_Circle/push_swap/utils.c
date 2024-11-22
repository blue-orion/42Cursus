/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:30:50 by takwak            #+#    #+#             */
/*   Updated: 2024/11/22 22:00:26 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstnext(char stack, t_pslst *lst)
{
	t_list	*cur;

	if (stack == 'a')
		cur = lst->a;
	if (stack == 'b')
		cur = lst->b;
	if (cur->sorted != 0)
	{
		if (stack == 'a')
			loop_command(lst, "ra", cur->sorted);
		// if (stack == 'b')
		// 	loop_command(lst, "rb", cur->sorted);
	}
	else
	{
		if (stack == 'a')
			ra(lst);
		// if (stack == 'b')
		// 	rb(lst);
		// if (stack == 'c')
		// 	rr(lst);
	}
}

// void	ft_lstpast(char stack, t_pslst *lst)
// {
// 	t_list	*cur;
//
// 	if (stack == 'a')
// 		cur = lst->a;
// 	if (stack == 'b')
// 		cur = lst->b;
// 	if (cur->sorted != 0)
// 	{
// 		if (stack == 'a')
// 			loop_command(lst, "rra", cur->sorted);
// 		if (stack == 'b')
// 			loop_command(lst, "rrb", cur->sorted);
// 	}
// 	else
// 	{
// 		if (stack == 'a')
// 			rra(lst);
// 		if (stack == 'b')
// 			rrb(lst);
// 		if (stack == 'c')
// 			rrr(lst);
// 	}
// }
void	run_command(t_pslst **lst, char *command)
{
	if (!ft_strcmp(command, "ra"))
		ra(lst);
	// if (!ft_strcmp(command, "rb"))
	// 	rb(lst);
	// if (!ft_strcmp(command, "rr"))
	// 	rr(lst);
	// if (!ft_strcmp(command, "pa"))
	// 	pa(lst);
	// if (!ft_strcmp(command, "pb"))
	// 	pb(lst);
	// if (!ft_strcmp(command, "rra"))
	// 	rra(lst);
	// if (!ft_strcmp(command, "rrb"))
	// 	rrb(lst);
	// if (!ft_strcmp(command, "rrr"))
	// 	rrr(lst);
	if (!ft_strcmp(command, "sa"))
		sa(lst);
	// if (!ft_strcmp(command, "sb"))
	// 	sb(lst);
	// if (!ft_strcmp(command, "ss"))
	// 	ss(lst);
}

void	loop_command(t_pslst **lst, char *command, int repeat_num)
{
	int	i;
	while (i < repeat_num)
	{
		run_command(lst, command);
		i++;
	}
}

void	*free_twoptr(void **ptr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(ptr[i++]);
	free(ptr);
	return (NULL);
}

int	count_data(int argc, char **argv)
{
	char	**splited;
	int		split_idx;
	int		i;
	int		cnt;

	cnt = 0;
	i = 1;
	while (i < argc)
	{
		splited = ft_split(argv[i], ' ');
		split_idx = 0;
		while (splited[split_idx])
		{
			cnt++;
			split_idx++;
		}
		free_twoptr((void **)splited, split_idx);
		i++;
	}
	return (cnt);
}

void	data_load(t_pslst *st, int argc, char **argv)
{
	char	**splited;
	int		i;
	int		split_idx;
	int		size;
	void	*data;

	size = count_data(argc, argv);
	i = 0;
	while (i < size)
	{
		split_idx = 0;
		splited = ft_split(argv[i], ' ');
		while (splited[split_idx])
		{
			*(int *)data = ft_atoi(splited[split_idx++]);
			st->a->next = ft_lstnew(&data);
		}
		free_twoptr((void **)splited, split_idx);
		i++;
	}
}

void	print_stack(t_pslst *st)
{
	t_list	*alst;
	t_list	*blst;

	alst = st->a;
	blst = st->b;
	ft_printf(" a stack | b stack\n");
	while (1)
	{
		if (alst == NULL && blst == NULL)
			break ;
		if (alst != NULL && blst == NULL)
		{
			ft_printf("%8d |        0\n", *(int *)alst->content);
			alst = alst->next;
		}
		if (alst == NULL && blst != NULL)
		{
			ft_printf("       0 | %8d\n", *(int *)blst->content);
			blst = blst->next;
		}
		if (alst != NULL && blst == NULL)
		{
			ft_printf("%8d | %8d\n", *(int *)alst->content, *(int *)blst->content);
			alst = alst->next;
			blst = blst->next;
		}
	}
}
