/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:30:50 by takwak            #+#    #+#             */
/*   Updated: 2024/11/21 20:48:51 by takwak           ###   ########.fr       */
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
	int		i;
	int		split_idx;
	int		size;

	size = count_data(argc, argv);
	st->a = (int *)ft_calloc(size + 1, sizeof(int));
	st->b = (int *)ft_calloc(size + 1, sizeof(int));
	i = 1;
	while (i < argc)
	{
		split_idx = 0;
		splited = ft_split(argv[i], ' ');
		while (splited[split_idx])
			st->a[++(st->a_idx)] = ft_atoi(splited[split_idx++]);
		free_twoptr((void **)splited, split_idx);
		i++;
	}
}

void	print_stack(t_ps *st)
{
	int	ai;
	int	bi;

	ai = 1;
	bi = 1;
	ft_printf("a stack | b stack\n");
	while (ai <= st->a_idx || bi <= st->b_idx)
	{
		ft_printf("%8d | %8d\n", st->a[ai++], st->b[bi++]);
	}
}
