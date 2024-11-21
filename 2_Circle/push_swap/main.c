/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:52:06 by takwak            #+#    #+#             */
/*   Updated: 2024/11/21 19:41:32 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	*st;

	st = (t_ps *)malloc(sizeof(t_ps));
	st->a_idx = 0;
	st->b_idx = 0;
	data_load(st, argc, argv);
	print_stack(st);
	free(st->a);
	free(st->b);
	free(st);
}
