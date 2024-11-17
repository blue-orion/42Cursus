/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 01:41:42 by takwak            #+#    #+#             */
/*   Updated: 2024/11/17 20:13:48 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_model(t_vars *s, char axis, double angle)
{
	mlx_destroy_image(s->mlx, s->img.img);
	s->img.img = mlx_new_image(s->mlx, WIDTH, HEIGHT);
	s->img.adr = mlx_get_data_addr(s->img.img, &s->img.bpp,
			&s->img.length, &s->img.endian);
	rotate_map(s->map, axis, angle * 0.1 * RADIAN);
	if (!ft_strncmp(s->projection, "conic", 6))
	{
		make_conic_image(s);
		return ;
	}
	move_init(s->map);
	move_center(s->map);
	render_x_line(&s->img, s->map);
	render_y_line(&s->img, s->map);
	mlx_put_image_to_window(s->mlx, s->win, s->img.img, 0, 0);
	put_info_string(s);
}
