/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:01:01 by takwak            #+#    #+#             */
/*   Updated: 2024/11/17 01:44:02 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define RADIAN 0.0174533

void	rotate_point(t_point *point, char axis, double theta)
{
	t_point	tmp;

	tmp.x = point->x;
	tmp.y = point->y;
	tmp.z = point->z;
	if (axis == 'x')
	{
		point->x = tmp.x;
		point->y = tmp.y * cos(theta) - tmp.z * sin(theta);
		point->z = tmp.y * sin(theta) + tmp.z * cos(theta);
	}
	if (axis == 'y')
	{
		point->x = tmp.x * cos(theta) + tmp.z * sin(theta);
		point->y = tmp.y;
		point->z = -1 * tmp.x * sin(theta) + tmp.z * cos(theta);
	}
	if (axis == 'z')
	{
		point->x = tmp.x * cos(theta) - tmp.y * sin(theta);
		point->y = tmp.x * sin(theta) + tmp.y * cos(theta);
		point->z = tmp.z;
	}
}

void	rotate_map(t_point **point, char axis, double theta)
{
	int	i;
	int	j;

	i = 1;
	while (i <= (*point)->y)
	{
		j = 1;
		while (j <= (*point)->x)
		{
			rotate_point(&point[i][j], axis, theta);
			j++;
		}
		i++;
	}
}

void	rotate_isometric(t_point *point)
{
	double	x;
	double	y;

	x = (point->x - point->y) * cos(30 * RADIAN);
	y = (point->x + point->y) * sin(30 * RADIAN) - point->z;
	point->x = x;
	point->y = y;
}
