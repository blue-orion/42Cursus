/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:52:06 by takwak            #+#    #+#             */
/*   Updated: 2024/12/08 01:34:05 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		cnt;
	t_ps	*st;

	if (argc < 2)
		return (0);
	cnt = 0;
	st = (t_ps *)malloc(sizeof(t_ps));
	data_load(st, argc, argv);
	if (!validate_data(st))
		ft_exit(st, NULL);
	indexing(st);
	if (is_sorted(st->a, st->a_idx))
		return (free_stack(st));
	greedy_sort(st, &cnt);
	return (free_stack(st));
}
