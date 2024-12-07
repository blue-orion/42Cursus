/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruct_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:00:29 by takwak            #+#    #+#             */
/*   Updated: 2024/12/07 20:15:38 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	run_instruct(char *inst, t_ps *st)
{
	if (!ft_strncmp(inst, "rra", 3))
		rra(st, 0);
	else if (!ft_strncmp(inst, "rrb", 3))
		rrb(st, 0);
	else if (!ft_strncmp(inst, "rrr", 3))
		rrr(st, 0);
	else if (!ft_strncmp(inst, "ra", 2))
		ra(st, 0);
	else if (!ft_strncmp(inst, "rb", 2))
		rb(st, 0);
	else if (!ft_strncmp(inst, "rr", 2))
		rr(st, 0);
	else if (!ft_strncmp(inst, "sa", 2))
		sa(st, 0);
	else if (!ft_strncmp(inst, "sb", 2))
		sb(st, 0);
	else if (!ft_strncmp(inst, "ss", 2))
		ss(st, 0);
	else if (!ft_strncmp(inst, "pa", 2))
		pa(st, 0);
	else if (!ft_strncmp(inst, "pb", 2))
		pb(st, 0);
	else
		ft_exit(st, NULL);
}

int	check_instruct(t_ps *st)
{
	char	*inst;

	inst = get_next_line(0);
	while (inst != NULL)
	{
		run_instruct(inst, st);
		inst = get_next_line(0);
	}
	if (st->b_idx == 0 && is_sorted(st->a, st->a_idx))
		return (1);
	else
		return (0);
}
