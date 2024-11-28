/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:21:48 by takwak            #+#    #+#             */
/*   Updated: 2024/11/27 18:38:01 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int *st, int size)
{
	int	i;
	int	min;

	i = 1;
	min = INT_MAX;
	while (i <= size)
	{
		if (st[i] < min)
			min = st[i];
		i++;
	}
	return (min);
}

int	find_min_idx(int *st, int size)
{
	int	min;
	int	i;

	i = 1;
	min = find_min(st, size);
	while (i <= size)
	{
		if (st[i] == min)
			return (i);
		i++;
	}
	return (0);
}

int	find_big_than(int *st, int size, int compare)
{
	int	top_find;
	int	bottom_find;
	int	r_num;
	int	rr_num;

	top_find = size;
	while (top_find >= size / 2)
	{
		if (st[top_find] > compare)
			break ;
		top_find--;
	}
	bottom_find = 1;
	while (bottom_find < size / 2)
	{
		if (st[bottom_find] > compare)
			break ;
		bottom_find++;
	}
	r_num = size - top_find;
	rr_num = bottom_find;
	if (r_num < rr_num)
		return (top_find);
	else
		return (-1 * bottom_find);
}

int	find_small_than(int *st, int size, int compare)
{
	int	top_find;
	int	bottom_find;
	int	r_num;
	int	rr_num;

	top_find = size;
	while (top_find >= size / 2)
	{
		if (st[top_find] < compare)
			break ;
		top_find--;
	}
	bottom_find = 1;
	while (bottom_find < size / 2)
	{
		if (st[bottom_find] < compare)
			break ;
		bottom_find++;
	}
	r_num = size - top_find;
	rr_num = bottom_find;
	if (r_num < rr_num)
		return (top_find);
	else
		return (-1 * bottom_find);
}

int	find_data(int *st, int size, int tofind)
{
	int	i;
	int	find;

	i = 1;
	find = 0;
	while (i <= size)
	{
		if (st[i] == tofind)
			find = i;
		i++;
	}
	if (find >= size / 2)
		return (size - find);
	else
		return (-1 * find);
}
