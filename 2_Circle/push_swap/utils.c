/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:30:50 by takwak            #+#    #+#             */
/*   Updated: 2024/12/07 20:23:27 by takwak           ###   ########.fr       */
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
	if (ptr == NULL)
		return (NULL);
	while (i < size)
		free(ptr[i++]);
	free(ptr);
	return (NULL);
}

int	is_sorted(int *st, int size)
{
	int	i;

	i = size;
	while (i > 1)
	{
		if (st[i] < st[i - 1])
			i--;
		else
			return (0);
	}
	return (1);
}
