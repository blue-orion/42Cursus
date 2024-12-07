/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:26:15 by takwak            #+#    #+#             */
/*   Updated: 2024/12/07 22:29:57 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_ps *st)
{
	int	i;
	int	j;

	i = 1;
	while (i <= st->a_idx)
	{
		j = 1;
		while (j <= st->a_idx)
		{
			if (st->a[i] == st->b[j])
			{
				st->a[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}
