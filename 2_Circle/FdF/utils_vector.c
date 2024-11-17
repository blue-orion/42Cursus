/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:51:51 by takwak            #+#    #+#             */
/*   Updated: 2024/11/17 18:49:33 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	vec_len(t_point p)
{
	return (sqrt(p.x * p.x + p.y * p.y + p.z * p.z));
}

t_point	*vec_norm(t_point *p)
{
	t_point	*res;
	float	len;

	len = vec_len(*p);
	res = (t_point *)malloc(sizeof(t_point));
	res->x = p->x / len;
	res->y = p->y / len;
	res->z = p->z / len;
	return (res);
}

t_point	*vec_cross(t_point *p1, t_point *p2)
{
	t_point	*res;

	res = (t_point *)malloc(sizeof(t_point));
	res->x = p1->y * p2->z - p1->z * p2->y;
	res->y = p1->z * p2->x - p1->x * p2->z;
	res->z = p1->x * p2->y - p1->y * p2->x;
	return (res);
}

t_point	*vec_sub(t_point *p1, t_point *p2)
{
	t_point	*res;

	res = (t_point *)malloc(sizeof(t_point));
	if (p2 == 0)
	{
		res->x = p1->x - 0;
		res->y = p1->y - 0;
		res->z = p1->z - 0;
	}
	else
	{
		res->x = p1->x - p2->x;
		res->y = p1->y - p2->y;
		res->z = p1->z - p2->z;
	}
	return (res);
}
