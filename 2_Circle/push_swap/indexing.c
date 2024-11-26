/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:26:15 by takwak            #+#    #+#             */
/*   Updated: 2024/11/24 16:18:09 by takwak           ###   ########.fr       */
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
		while(j <= st->a_idx)
		{
			if (st->a[j] == st->b[i])
			{
				st->a[j] = i;
				st->b[i] = 0;
				break ;
			}
			j++;
		}
		i++;
	}
}
