/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:30:50 by takwak            #+#    #+#             */
/*   Updated: 2024/11/27 18:43:16 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n > 0)
		return (n);
	else
		return (-1 * n);
}

void	*free_twoptr(void **ptr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(ptr[i++]);
	free(ptr);
	return (NULL);
}

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
