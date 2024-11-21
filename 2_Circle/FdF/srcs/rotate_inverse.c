/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:26:04 by takwak            #+#    #+#             */
/*   Updated: 2024/11/16 23:16:48 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_inverse_point(t_point *point, char axis, double theta)
{
	t_point	tmp;

	tmp.x = point->x;
	tmp.y = point->y;
	tmp.z = point->z;
	if (axis == 'x')
	{
		point->x = tmp.x;
		point->y = tmp.y * cos(theta) + tmp.z * sin(theta);
		point->z = tmp.y * -1 * sin(theta) + tmp.z * cos(theta);
	}
	if (axis == 'y')
	{
		point->x = tmp.x * cos(theta) - tmp.z * sin(theta);
		point->y = tmp.y;
		point->z = tmp.x * sin(theta) + tmp.z * cos(theta);
	}
	if (axis == 'z')
	{
		point->x = tmp.x * cos(theta) + tmp.y * sin(theta);
		point->y = tmp.x * -1 * sin(theta) + tmp.y * cos(theta);
		point->z = tmp.z;
	}
}

void	rotate_inverse_map(t_point **point, char axis, double theta)
{
	int	i;
	int	j;

	i = 1;
	while (i <= (*point)->y)
	{
		j = 1;
		while (j <= (*point)->x)
		{
			rotate_inverse_point(&point[i][j], axis, theta);
			j++;
		}
		i++;
	}
}
