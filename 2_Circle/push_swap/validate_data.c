/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:41:39 by takwak            #+#    #+#             */
/*   Updated: 2024/12/06 23:16:52 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exist_same_num(t_ps *st)
{
	int	i;
	int	j;
	int	num;

	i = 1;
	while (i < st->a_idx)
	{
		num = st->a[i];
		j = i + 1;
		while (j <= st->a_idx)
		{
			if (num == st->a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_data(t_ps *st)
{
	if (exist_same_num(st))
		return (0);
	return (1);
}
