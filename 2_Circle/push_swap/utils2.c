/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:47:25 by takwak            #+#    #+#             */
/*   Updated: 2024/12/08 01:36:07 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

int	free_stack(t_ps *st)
{
	if (st->a != NULL)
		free(st->a);
	if (st->b != NULL)
		free(st->b);
	if (st != NULL)
		free(st);
	return (0);
}

int	ft_exit(t_ps *st, int *tmp)
{
	write(2, "Error\n", 6);
	if (tmp != NULL)
		free(tmp);
	free_stack(st);
	exit(EXIT_FAILURE);
}

void	init_stack(t_ps *st)
{
	st->a_idx = 0;
	st->b_idx = 0;
	st->a = (int *)ft_calloc(st->size + 1, sizeof(int));
	st->b = (int *)ft_calloc(st->size + 1, sizeof(int));
	if (st->a == NULL || st->b == NULL)
		ft_exit(st, NULL);
}
