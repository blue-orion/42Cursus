/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:06:58 by takwak            #+#    #+#             */
/*   Updated: 2024/11/15 02:32:17 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define PI 3.14159265
#define radian 0.0174533

//35.264 is arcsin(tan(30 degree))
void	calculate_isometric(t_point **matrix)
{
	int	i;
	int	j;

	i = 1;
	while (i <= (int)matrix[0]->y)
	{
		j = 1;
		while (j <= (int)matrix[0]->x)
		{
			trans(&matrix[i][j]);
			printf("%.2f %.2f %.2f\n", matrix[i][j].x, matrix[i][j].y, matrix[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	create_trgb(t_point point)
{
	return (point.t << 24 | point.r << 16 | point.g << 8 | point.b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->adr + y * data->line_length + x * (data->bpp / 8);
	*(unsigned int*)dst = color;
}

void	make_isometric_img(t_point **matrix, t_vars *s)
{
	t_data	img;
	int		i;
	int		j;

	calculate_isometric(matrix);
	make_max_size(matrix);
	move_center(matrix);
	print_matrix(matrix);
	img.img = mlx_new_image(s->mlx, WIDTH, HEIGHT);
	img.adr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	i = 1;
	while (i <= matrix[0]->y)
	{
		j = 1;
		while (j < matrix[0]->x)
		{
			if (matrix[i][j].x < matrix[i][j + 1].x)
				render_line_bresenham(&img, matrix[i][j], matrix[i][j + 1]);
			else
				render_line_bresenham(&img, matrix[i][j + 1], matrix[i][j]);

			j++;
		}
		i++;
	}
	i = 1;
	while (i <= matrix[0]->x)
	{
		j = matrix[0]->y;
		while (j > 1)
		{
			if (matrix[j][i].x < matrix[j - 1][i].x)
				render_line_bresenham(&img, matrix[j][i], matrix[j - 1][i]);
			else
				render_line_bresenham(&img, matrix[j - 1][i], matrix[j][i]);
			j--;
		}
		i++;
	}
	mlx_put_image_to_window(s->mlx, s->win, img.img, 0, 0);
}
