/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:17:49 by takwak            #+#    #+#             */
/*   Updated: 2024/11/14 20:45:49 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	print_matrix(t_point **matrix)
{
	int	i;
	int	j;

	i = 1;
	while (i <= matrix[0]->y)
	{
		j = 1;
		while (j <= matrix[0]->x)
		{
			printf("(%.2f, %.2f, %.2f)\n", matrix[i][j].x, matrix[i][j].y, matrix[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
}
