/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_conic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:30:34 by takwak            #+#    #+#             */
/*   Updated: 2024/11/17 18:43:57 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_conic(t_point *p)
{
	double	fov;
	double	a;
	double	n;
	double	f;

	fov = 60 * RADIAN;
	a = WIDTH / HEIGHT;
	n = 1;
	f = 1.1;
	p->x = p->x / (a * tan(fov / 2));
	p->y = p->y / tan(fov / 2);
	p->z = ((f + n) * p->z) + 2 * f * n / (f - n);
	p->x = p->x / (-1 * p->z);
	p->y = p->y / (-1 * p->z);
	p->z = p->z / (-1 * p->z);
	p->x = (WIDTH / 2) * (p->x + 1);
	p->y = (HEIGHT / 2) * (1 - p->y);
}

void	conic_projection(t_point **map)
{
	int	i;
	int	j;

	i = 1;
	while (i <= (*map)->y)
	{
		j = 1;
		while (j <= (*map)->x)
		{
			calculate_conic(&map[i][j]);
			j++;
		}
		i++;
	}
}

void	make_conic_image(t_vars *s)
{
	t_point	**view;

	view = NULL;
	if (s->img.img != NULL)
		mlx_destroy_image(s->mlx, s->img.img);
	s->img.img = mlx_new_image(s->mlx, WIDTH, HEIGHT);
	s->img.adr = mlx_get_data_addr(s->img.img, &s->img.bpp,
			&s->img.length, &s->img.endian);
	copy_matrix(&view, &s->map);
	if (view == NULL)
		ft_perror("Failed Malloc\n");
	apply_scale(view, s->scale);
	camera_map(view);
	conic_projection(view);
	apply_scale(view, 1.1);
	move_init(view);
	move_center(view);
	render_x_line(&s->img, view);
	render_y_line(&s->img, view);
	free_twoptr((void **)view, s->src_map[0]->y + 1);
	mlx_put_image_to_window(s->mlx, s->win, s->img.img, 0, 0);
	put_info_string(s);
}
