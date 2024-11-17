/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_isometric.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:06:58 by takwak            #+#    #+#             */
/*   Updated: 2024/11/17 18:44:15 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_isometric(t_point **map)
{
	int	i;
	int	j;

	i = 1;
	while (i <= (int)map[0]->y)
	{
		j = 1;
		while (j <= (int)map[0]->x)
		{
			rotate_isometric(&map[i][j]);
			j++;
		}
		i++;
	}
}

void	make_isometric_image(t_vars *s)
{
	copy_matrix(&s->map, &s->src_map);
	if (s->img.img != NULL)
		mlx_destroy_image(s->mlx, s->img.img);
	s->img.img = mlx_new_image(s->mlx, WIDTH, HEIGHT);
	s->img.adr = mlx_get_data_addr(s->img.img, &s->img.bpp,
			&s->img.length, &s->img.endian);
	apply_scale(s->map, s->scale);
	calculate_isometric(s->map);
	move_center(s->map);
	render_x_line(&s->img, s->map);
	render_y_line(&s->img, s->map);
	mlx_put_image_to_window(s->mlx, s->win, s->img.img, 0, 0);
	put_info_string(s);
}
