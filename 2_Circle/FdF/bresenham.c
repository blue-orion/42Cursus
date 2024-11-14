/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:53:49 by takwak            #+#    #+#             */
/*   Updated: 2024/11/15 00:31:04 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define ROUND(n) ((int)n != (int)(n + 0.5) ? (int)n + 1 : (int)n)

int	ft_sub(double a, double b)
{
	return ((int)a - (int)b);
}

int	discriminant(double m, int f, t_pixel p1, t_pixel p2)
{
	int	f2;

	if (m < -1)
	{
		f2 = f + 2 * (p2.x - p1.x);
		if (f > 0)
			f2 = f2 + 2 * (p2.y - p1.y);
		return (f2);
	}
	if (m >= -1 && m < 0)
	{
		f2 = f - 2 * (p2.y - p1.y);
		if (f > 0)
			f2 = f2 - 2 * (p2.x - p1.x);
		return (f2);
	}
	if (m >= 0 && m < 1)
	{
		f2 = f + 2 * (p2.y - p1.y);
		if (f > 0)
			f2 = f2 - 2 * (p2.x - p1.x);
		return (f2);
	}
	if (m >= 1)
	{
		f2 = f - 2 * (p2.x - p1.x);
		if (f < 0)
			f2 = f2 + 2 * (p2.y - p1.y);
		return (f2);
	}
	return (0);
}

void	data_preprocess(t_pixel *dst, t_point src)
{
	// dst->x = ROUND(src.x);
	// dst->y = ROUND(src.y);
	// dst->color = create_trgb(src);
	dst->x = (int)src.x;
	dst->y = (int)src.y;
	dst->color = create_trgb(src);
}

void	render_line_bresenham(t_data *img, t_point start, t_point end)
{
	t_pixel	p1;
	t_pixel	p2;
	t_pixel cur;
	int		f;
	double	m;

	data_preprocess(&p1, start);
	data_preprocess(&p2, end);
	data_preprocess(&cur, start);
	printf("(%d, %d) -> (%d, %d)\n", p1.x, p1.y, p2.x, p2.y);
	if (p2.x - p1.x == 0)
	{
		if (p2.y - p1.y > 0)
		{
			while (cur.y != p2.y)
			{
				printf("(%d, %d) color = %x\n", cur.x, cur.y, cur.color);
				my_mlx_pixel_put(img, cur.x, cur.y, cur.color);
				cur.y++;
			}
		}
		else
		{
			while (cur.y != p2.y)
			{
				printf("(%d, %d) color = %x\n", cur.x, cur.y, cur.color);
				my_mlx_pixel_put(img, cur.x, cur.y, cur.color);
				cur.y--;
			}
		}
		my_mlx_pixel_put(img, cur.x, cur.y, cur.color);
		return ;
	}
	else
		m = (double)(p2.y - p1.y) / (double)(p2.x - p1.x);
	printf("m = %.2f\n", m);
	if (m >= 1)
	{
		f = -2 * (p2.x - p1.x)  + (p2.y - p1.y);
		while (cur.y != p2.y)
		{
			printf("(%d, %d) color = %x\n", cur.x, cur.y, cur.color);
			my_mlx_pixel_put(img, cur.x, cur.y, cur.color);
			if (f < 0)
				cur.x += 1;
			cur.y++;
			f = discriminant(m, f, p1, p2);
		}
	}
	if (m < 1 && m >= 0)
	{
		f = 2 * (p2.y - p1.y) - (p2.x - p1.x);
		while (cur.x != p2.x)
		{
			printf("F() = %d | ", f);
			printf("(%d, %d) color = %x\n", cur.x, cur.y, cur.color);
			my_mlx_pixel_put(img, cur.x, cur.y, cur.color);
			if (f > 0)
				cur.y += 1;
			cur.x++;
			if (cur.x >= 1080)
				exit(1);
			f = discriminant(m, f, p1, p2);
		}
	}
	if (m >= -1 && m < 0)
	{
		f = -2 * (p2.y - p1.y) + (p2.x - p1.x);
		while (cur.x != p2.x)
		{
			printf("(%d, %d) color = %x\n", cur.x, cur.y, cur.color);
			my_mlx_pixel_put(img, cur.x, cur.y, cur.color);
			if (f > 0)
			{
				cur.y -= 1;
			}
			cur.x++;
			if (cur.x >= 1080)
				exit(1);
			f = discriminant(m, f, p1, p2);
		}
	}
	if (m < -1)
	{
		f = 2 * (p2.x - p1.x) + (p2.y - p1.y);
		while (cur.y != p2.y)
		{
			printf("(%d, %d) color = %x\n", cur.x, cur.y, cur.color);
			my_mlx_pixel_put(img, cur.x, cur.y, cur.color);
			if (f > 0)
				cur.x += 1;
			cur.y--;
			f = discriminant(m, f, p1, p2);
		}
	}
	if (cur.x >= 1080)
		exit(1);
	printf("(%d, %d) color = %x\n", cur.x, cur.y, cur.color);
	my_mlx_pixel_put(img, cur.x, cur.y, cur.color);
}
