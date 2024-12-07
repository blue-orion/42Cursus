/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruct_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:00:29 by takwak            #+#    #+#             */
/*   Updated: 2024/12/08 01:20:04 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_gnl(int fd)
{
	char	*buf;

	buf = get_next_line(fd);
	while (buf != NULL)
	{
		free(buf);
		buf = get_next_line(fd);
	}
	free(buf);
}

int	run_instruct(char *inst, t_ps *st)
{
	if (!ft_strncmp(inst, "rra\n", 4))
		rra(st, 0);
	else if (!ft_strncmp(inst, "rrb\n", 4))
		rrb(st, 0);
	else if (!ft_strncmp(inst, "rrr\n", 4))
		rrr(st, 0);
	else if (!ft_strncmp(inst, "ra\n", 3))
		ra(st, 0);
	else if (!ft_strncmp(inst, "rb\n", 3))
		rb(st, 0);
	else if (!ft_strncmp(inst, "rr\n", 3))
		rr(st, 0);
	else if (!ft_strncmp(inst, "sa\n", 3))
		sa(st, 0);
	else if (!ft_strncmp(inst, "sb\n", 3))
		sb(st, 0);
	else if (!ft_strncmp(inst, "ss\n", 3))
		ss(st, 0);
	else if (!ft_strncmp(inst, "pa\n", 3))
		pa(st, 0);
	else if (!ft_strncmp(inst, "pb\n", 3))
		pb(st, 0);
	else
		return (0);
	return (1);
}

int	check_instruct(t_ps *st)
{
	char	*inst;

	inst = get_next_line(0);
	while (inst != NULL)
	{
		if (!run_instruct(inst, st))
		{
			free(inst);
			free_gnl(-1);
			ft_exit(st, NULL);
		}
		free(inst);
		inst = get_next_line(0);
	}
	if (st->b_idx == 0 && is_sorted(st->a, st->a_idx))
		return (1);
	else
		return (0);
}
