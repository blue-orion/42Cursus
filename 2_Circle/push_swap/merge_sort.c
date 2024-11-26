/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:42:50 by takwak            #+#    #+#             */
/*   Updated: 2024/11/24 15:35:27 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge(int *arr, int *sorted, int left, int right)
{
	int	i;
	int	j;
	int	k;
	int	mid;

	mid = (left + right) / 2;
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}
	if (i > mid)
		while (j <= right)
			sorted[k++] = arr[j++];
	if (j > right)
		while (i <= mid)
			sorted[k++] = arr[i++];
	while (left <= right)
	{
		arr[left] = sorted[left];
		left++;
	}
}

void	merge_sort(int *arr, int *sorted, int left, int right)
{
	int	mid;

	if (left >= right)
		return ;
	mid = (left + right) / 2;
	merge_sort(arr, sorted, left, mid);
	merge_sort(arr, sorted, mid + 1, right);
	merge(arr, sorted, left, right);
}
