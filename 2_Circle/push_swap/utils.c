/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:30:50 by takwak            #+#    #+#             */
/*   Updated: 2024/11/26 03:31:33 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	data_load(t_ps *st, int argc, char **argv)
{
	char	**splited;
	int		*tmp;
	int		i;
	int		split_idx;

	st->size = count_data(argc, argv);
	st->a = (int *)ft_calloc(st->size + 1, sizeof(int));
	st->b = (int *)ft_calloc(st->size + 1, sizeof(int));
	tmp = (int *)ft_calloc(st->size + 1, sizeof(int));
	i = 1;
	while (i < argc)
	{
		split_idx = 0;
		splited = ft_split(argv[i], ' ');
		while (splited[split_idx])
		{
			st->a[++(st->a_idx)] = ft_atoi(splited[split_idx]);
			tmp[st->a_idx] = ft_atoi(splited[split_idx++]);
		}
		free_twoptr((void **)splited, split_idx);
		i++;
	}
	ft_reverse(st->a, st->size);
	ft_reverse(tmp, st->size);
	merge_sort(tmp, st->b, 1, st->size);
	free(tmp);
}

void	print_stack(t_ps *st)
{
	int	ai;
	int	bi;

	// usleep(100000);
	// for (int i = 0; i < 40; i++)
	// 	ft_printf("\n");
	ai = st->a_idx;
	bi = st->b_idx;
	// ft_printf(" a stack | b stack\n");
	while (ai >= 1 || bi >= 1)
	{
		// if (st->a[ai] == 0 && st->b[bi] == 0)
		// 	ft_printf("         |         \n");
		// if (st->a[ai] != 0 && st->b[bi] == 0)
		// 	ft_printf("%8d |         \n", st->a[ai]);
		// if (st->a[ai] == 0 && st->b[bi] != 0)
		// 	ft_printf("         | %8d\n", st->b[bi]);
		// if (st->a[ai] != 0 && st->b[bi] != 0)
		// 	ft_printf("%8d | %8d\n", st->a[ai], st->b[bi]);
		if (ai >= 1)
			ai--;
		if (bi >= 1)
			bi--;
	}
}

int	count_cmd(t_ps *st, char *cmd)
{
	if (!ft_strncmp(cmd, "ra", 2))
		user_ra(st);
	if (!ft_strncmp(cmd, "rb", 2))
		user_rb(st);
	if (!ft_strncmp(cmd, "rr", 2))
		user_rr(st);
	if (!ft_strncmp(cmd, "rra", 3))
		user_rra(st);
	if (!ft_strncmp(cmd, "rrb", 3))
		user_rrb(st);
	if (!ft_strncmp(cmd, "rrr", 3))
		user_rrr(st);
	if (!ft_strncmp(cmd, "sa", 2))
		user_sa(st);
	if (!ft_strncmp(cmd, "sb", 2))
		user_sb(st);
	if (!ft_strncmp(cmd, "ss", 2))
		user_ss(st);
	if (!ft_strncmp(cmd, "pa", 2))
		user_pa(st);
	if (!ft_strncmp(cmd, "pb", 2))
		user_pb(st);
	return (1);
}
