/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:48:07 by takwak            #+#    #+#             */
/*   Updated: 2024/11/25 21:54:38 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_interval(int n, int *st, int a, int b)
{
	if (st[a] + n == st[b] || st[a] - n == st[b])
		return (1);
	return (0);
}

int	is_sorted(int order, int *st, int size)
{
	int i;

	i = 1;
	while (i < size)
	{
		if (st[i] + order == st[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
