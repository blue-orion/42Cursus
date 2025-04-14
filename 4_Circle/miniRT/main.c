/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:33:38 by takwak            #+#    #+#             */
/*   Updated: 2025/04/05 16:19:29 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	draw_circle(t_mlx *vars);

int	main(void)
{
	t_mlx	vars;
	t_img	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 960, 720, "Hello world!");
	img.imgp = mlx_new_image(vars.mlx, 480, 360);
	img.adr = mlx_get_data_addr(img.imgp, &img.bpp, &img.length, &img.endian);
	vars.img = &img;
	mlx_hook(vars.win, ON_DESTROY, 0, end_program, &vars);
	mlx_hook(vars.win, ON_KEYDOWN, 1L>>0, key_hook, &vars);
	draw_circle(&vars);
	mlx_loop(vars.mlx);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->adr + (y * data->length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_circle(t_mlx *vars)
{
	t_point	c;
	int		r;

	c.x = 240;
	c.y = 180;
	c.z = 0;
	r = 100;
	for (double i = 0; i <= PI; i += 0.001)
	{
		for (double j = 0; j <= 2*PI; j += 0.001)
		{
			double x = r * sin(i) * cos(j) + c.x;
			double y = r * sin(i) * sin(j) + c.y;
			double z = r * cos(i) + c.z;

			my_mlx_pixel_put(vars->img, x, y, 0xFFFFFF);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->imgp, 400, 300);
}
