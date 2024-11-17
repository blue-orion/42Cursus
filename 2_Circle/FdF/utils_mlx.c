/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:36:14 by takwak            #+#    #+#             */
/*   Updated: 2024/11/17 22:51:12 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_trgb(t_point point)
{
	return (point.t << 24 | point.r << 16 | point.g << 8 | point.b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		dst = data->adr + y * data->length + x * (data->bpp / 8);
		*(unsigned int *)dst = color;
	}
}

void	data_preprocess(t_pixel *dst, t_point src)
{
	dst->x = (int)src.x;
	dst->y = (int)src.y;
	dst->color = create_trgb(src);
}

void	make_image(t_vars *s)
{
	if (!ft_strncmp(s->projection, "isometric", 10))
		make_isometric_image(s);
	if (!ft_strncmp(s->projection, "conic", 6))
	{
		copy_matrix(&s->map, &s->src_map);
		make_conic_image(s);
	}
}
