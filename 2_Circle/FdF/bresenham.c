/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:53:49 by takwak            #+#    #+#             */
/*   Updated: 2024/11/15 03:28:01 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	plus_discriminant(double m, int f, t_pixel p1, t_pixel p2)
{
	int	f2;

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

int	minus_discriminant(double m, int f, t_pixel p1, t_pixel p2)
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
	return (0);
}

void	render_line_bresenham(t_data *img, t_point start, t_point end)
{
	t_pixel	p1;
	t_pixel	p2;
	double	m;

	data_preprocess(&p1, start);
	data_preprocess(&p2, end);
	if (p2.x - p1.x == 0)
	{
		zero_lean(img, p1, p2);
		return ;
	}
	else
		m = (double)(p2.y - p1.y) / (double)(p2.x - p1.x);
	if (m >= 1)
		plus_lean_more_one(m, img, p1, p2);
	if (m < 1 && m >= 0)
		plus_lean_less_one(m, img, p1, p2);
	if (m >= -1 && m < 0)
		minus_lean_less_one(m, img, p1, p2);
	if (m < -1)
		minus_lean_more_one(m, img, p1, p2);
}
