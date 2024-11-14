/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:28:26 by takwak            #+#    #+#             */
/*   Updated: 2024/11/13 12:22:28 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_point(t_point *point)
{
	point->x = 0;
	point->y = 0;
	point->z = 0;
	point->t = 0;
	point->r = 255;
	point->g = 255;
	point->b = 255;
}

t_point	**make_matrix(t_point *info)
{
	int		i;
	int		j;
	t_point	**matrix;

	matrix = (t_point **)malloc(sizeof(t_point *) * (info->y + 1));
	matrix[0] = (t_point *)malloc(sizeof(t_point));
	matrix[0][0].x = info->x;
	matrix[0][0].y = info->y;
	i = 1;
	while (i < info->y + 1)
	{
		matrix[i] = (t_point *)malloc(sizeof(t_point) * (info->x + 1));
		j = 0;
		while (j < info->x + 1)
			init_point(&matrix[i][j++]);
		i++;
	}
	return (matrix);
}
