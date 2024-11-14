/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:01:01 by takwak            #+#    #+#             */
/*   Updated: 2024/11/15 02:32:06 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define radian 0.0174533

void	trans_matrix(t_point *point, char axis, double theta)
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
		point->x = tmp.x * cos(theta) - tmp.z * sin(theta);
		point->y = tmp.y;
		point->z = tmp.x * sin(theta) + tmp.z * cos(theta);
	}
	if (axis == 'z')
	{
		point->x = tmp.x * cos(theta) - tmp.y * sin(theta);
		point->y = tmp.x * sin(theta) + tmp.y * cos(theta);
		point->z = tmp.z;
	}
}

// void	trans(t_point *point)
// {
// 	double	x;
// 	double	y;
// 	double	theta;
//
// 	theta = asin(tan(30 * radian));
// 	x = point->x * cos(45 * radian) - point->y * sin(45 * radian);
// 	y = point->x * cos(theta) * sin(45 * radian) + point->y * cos(theta) * cos(45 * radian) - sin(theta) * point->z;
// 	point->x = x;
// 	point->y = y;
// }

void	trans(t_point *point)
{
	double	x;
	double	y;

	x = (point->x - point->y) * cos(30 * radian);
	y = (point->x + point->y) * sin(30 * radian) - point->z;
	point->x = x;
	point->y = y;
}
