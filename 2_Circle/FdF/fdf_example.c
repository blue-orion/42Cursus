/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_example.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:18:44 by takwak            #+#    #+#             */
/*   Updated: 2024/11/11 02:31:15 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define PI 3.141592

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->adr + y * data->line_length + x * (data->bpp / 8);
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	win_close(int keycode, t_vars *vars)
{
	printf("you press : %d\n", (unsigned char)keycode);
	if ((unsigned char)keycode == 1 || (unsigned char)keycode == 27)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	render_next_frame(void *s)
{
	t_vars	vars;
	t_data	img;

	vars = *(t_vars *)s;
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.adr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	for (int i = 0; i < 255; i++)
	{
		for (int j = 0; j < 255; j = j + 100 * cos(30 * (PI / 180)))
		{
			my_mlx_pixel_put(&img, i, j, create_trgb(0, i, 0, 0));
			mlx_put_image_to_window(vars.mlx, vars.win, img.img, 100, 100);
		}
	}
}

int	discriminant(t_point *start, t_point *end, t_point *cur)
{
	int	res;
	int	post_d;
	int	pre_d;

	pre_d = 2 * (end->y - start->y) * (start->x - cur->x);
	post_d = 2 * (end->x - start->x) * (cur->y - start->y);
	res = pre_d + post_d;
	return (res >= 0);
}

void	render_crossline_bresenham(t_vars *s, t_data *img, t_point start, t_point end)
{
	t_vars	vars;
	t_data	img;
	t_point	cur;

	vars = *(t_vars *)s;
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.adr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	start.x = 10;
	start.y = 10;
	end.x = 490;
	end.y = 400;
	cur.x = start.x;
	cur.y = start.y;
	while (cur.x != end.x)
	{
		my_mlx_pixel_put(&img, cur.x, cur.y, create_trgb(0, 0, 255, 0));
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, start.x, start.y);
		if (discriminant(&start, &end, &cur))
			cur.x++;
		else
		{
			cur.x++;
			cur.y++;
		}
	}
}

void	render_crossline(void *s)
{
	t_vars	vars;
	t_data	img;
	double		x = 10;
	double		y = 10;

	vars = *(t_vars *)s;
	img.img = mlx_new_image(vars.mlx, 1000, 1000);
	img.adr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	for (int i = 0; i < 255; i++)
	{
		for (int j = 0; j < 255; j++)
		{
			x = j;
			y = i + -(tan(45 * (PI / 180)) * j) + 255;
			printf("cos(45) = %f | sin(45) = %f\n", cos(45 * (PI / 180)), sin(45 * (PI / 180)));
			printf("x = %f | y = %f\n", x, y);
			my_mlx_pixel_put(&img, x, y, create_trgb(0, j, 0, 0));
			mlx_put_image_to_window(vars.mlx, vars.win, img.img, 100, 100);
		}
	}
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1000, 1000);
	img.adr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	printf("img.img = %p\nimg.bpp = %d\nimg.line_length = %d\nimg.endian = %d\n", img.img, img.bpp, img.line_length, img.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 100, 100);
	mlx_key_hook(vars.win, win_close, &vars);
	mlx_loop_hook(vars.mlx, render_crossline_bresenham, &vars);
	mlx_loop(vars.mlx);
}
