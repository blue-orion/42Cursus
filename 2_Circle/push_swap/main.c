/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:52:06 by takwak            #+#    #+#             */
/*   Updated: 2024/11/27 17:46:55 by takwak           ###   ########.fr       */
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
	print_stack(st);
	indexing(st);
	if (is_sorted(-1, st->a, st->a_idx))
		return (0);
	if (is_sorted(1, st->a, st->a_idx))
		return (0);
	divide(st, &cnt);
	greedy_sort(st, &cnt);
	// radix_atob(st, 10, &cnt);
	print_stack(st);
	printf("cnt cmd = %d\n", cnt);
	free(st->a);
	free(st->b);
	free(st);
}
