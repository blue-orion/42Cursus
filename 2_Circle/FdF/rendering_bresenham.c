/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bresenham.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:25:46 by takwak            #+#    #+#             */
/*   Updated: 2024/11/16 00:21:07 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plus_lean_more_one(double m, t_data *img, t_pixel p1, t_pixel p2)
{
	t_pixel	cur;
	int		f;

	cur.x = p1.x;
	cur.y = p1.y;
	cur.color = p1.color;
	f = -2 * (p2.x - p1.x) + (p2.y - p1.y);
	while (cur.y != p2.y)
	{
		my_mlx_pixel_put(img, cur.x, cur.y, cur.color);
		if (f < 0)
			cur.x += 1;
		cur.y++;
		f = plus_discriminant(m, f, p1, p2);
	}
	my_mlx_pixel_put(img, cur.x, cur.y, cur.color);
}

void	plus_lean_less_one(double m, t_data *img, t_pixel p1, t_pixel p2)
{
	t_pixel	cur;
	int		f;

	cur.x = p1.x;
	cur.y = p1.y;
	cur.color = p1.color;
	f = 2 * (p2.y - p1.y) - (p2.x - p1.x);
	while (cur.x != p2.x)
	{
		my_mlx_pixel_put(img, cur.x, cur.y, cur.color);
		if (f > 0)
			cur.y += 1;
		cur.x++;
		f = plus_discriminant(m, f, p1, p2);
	}
	my_mlx_pixel_put(img, cur.x, cur.y, cur.color);
}

void	minus_lean_less_one(double m, t_data *img, t_pixel p1, t_pixel p2)
{
	t_pixel	cur;
	int		f;

	cur.x = p1.x;
	cur.y = p1.y;
	cur.color = p1.color;
	f = -2 * (p2.y - p1.y) + (p2.x - p1.x);
	while (cur.x != p2.x)
	{
		my_mlx_pixel_put(img, cur.x, cur.y, cur.color);
		if (f > 0)
			cur.y -= 1;
		cur.x++;
		f = minus_discriminant(m, f, p1, p2);
	}
	my_mlx_pixel_put(img, cur.x, cur.y, cur.color);
}

void	minus_lean_more_one(double m, t_data *img, t_pixel p1, t_pixel p2)
{
	t_pixel	cur;
	int		f;

	cur.x = p1.x;
	cur.y = p1.y;
	cur.color = p1.color;
	f = 2 * (p2.x - p1.x) + (p2.y - p1.y);
	while (cur.y != p2.y)
	{
		my_mlx_pixel_put(img, cur.x, cur.y, cur.color);
		if (f > 0)
			cur.x += 1;
		cur.y--;
		f = minus_discriminant(m, f, p1, p2);
	}
	my_mlx_pixel_put(img, cur.x, cur.y, cur.color);
}

void	zero_lean(t_data *img, t_pixel p1, t_pixel p2)
{
	t_pixel	cur;

	cur = p1;
	if (p2.y - p1.y > 0)
	{
		while (cur.y != p2.y)
		{
			my_mlx_pixel_put(img, cur.x, cur.y, cur.color);
			cur.y++;
		}
	}
	else
	{
		while (cur.y != p2.y)
		{
			my_mlx_pixel_put(img, cur.x, cur.y, cur.color);
			cur.y--;
		}
	}
	my_mlx_pixel_put(img, cur.x, cur.y, cur.color);
}
