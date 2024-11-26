/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:34:52 by takwak            #+#    #+#             */
/*   Updated: 2024/11/25 16:38:56 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse(int *st, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	j = size;
	while (i <= size / 2)
	{
		tmp = st[i];
		st[i] = st[j];
		st[j] = tmp;
		i++;
		j--;
	}
}
