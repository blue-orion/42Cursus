/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:52:06 by takwak            #+#    #+#             */
/*   Updated: 2024/12/06 23:43:03 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		cnt;
	t_ps	*st;

	cnt = 0;
	st = (t_ps *)malloc(sizeof(t_ps));
	st->a_idx = 0;
	st->b_idx = 0;
	st->size = 0;
	data_load(st, argc, argv);
	if (!validate_data(st))
	{
		write(2, "Error\n", 6);
		free_stack(st);
		return (0);
	}
	indexing(st);
	print_stack(st->a, st->a_idx);
	print_stack(st->b, st->a_idx);
	if (is_sorted(-1, st->a, st->a_idx))
		return (free_stack(st));
	divide(st, &cnt);
	greedy_two_sort(st, &cnt);
	printf("cnt cmd = %d\n", cnt);
	free_stack(st);
	return (0);
}
