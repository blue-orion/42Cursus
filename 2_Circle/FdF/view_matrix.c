/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 03:09:26 by takwak            #+#    #+#             */
/*   Updated: 2024/11/17 21:21:42 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trans_cam_point(t_point *p, t_point *pos_cam, t_point *up, t_point src)
{
	t_point	*x_cam;
	t_point	*y_cam;
	t_point	*z_cam;
	t_point	*tmp;

	tmp = vec_sub(pos_cam, 0);
	z_cam = vec_norm(tmp);
	free(tmp);
	tmp = vec_cross(z_cam, up);
	x_cam = vec_norm(tmp);
	x_cam->x *= -1;
	y_cam = vec_cross(x_cam, z_cam);
	p->x = x_cam->x * src.x + x_cam->y * src.y + x_cam->z * src.z
		- x_cam->x * pos_cam->x - x_cam->y * pos_cam->y - x_cam->z * pos_cam->z;
	p->y = y_cam->x * src.x + y_cam->y * src.y + y_cam->z * src.z
		- y_cam->x * pos_cam->x - y_cam->y * pos_cam->y - y_cam->z * pos_cam->z;
	p->z = z_cam->x * src.x + z_cam->y * src.y + z_cam->z * src.z
		- z_cam->x * pos_cam->x - z_cam->y * pos_cam->y - z_cam->z * pos_cam->z;
	free(x_cam);
	free(y_cam);
	free(z_cam);
	free(tmp);
}

void	camera_map(t_point **map)
{
	t_point	pos_cam;
	t_point	src;
	t_point	up;
	int		i;
	int		j;

	pos_cam.x = 0.0f;
	pos_cam.y = 0.0f;
	pos_cam.z = 700.0f;
	up.x = 0.0f;
	up.y = 1.0f;
	up.z = 0.0f;
	i = 1;
	while (i <= (*map)->y)
	{
		j = 1;
		while (j <= (*map)->x)
		{
			src.x = map[i][j].x;
			src.y = map[i][j].y;
			src.z = map[i][j].z;
			trans_cam_point(&map[i][j++], &pos_cam, &up, src);
		}
		i++;
	}
}
