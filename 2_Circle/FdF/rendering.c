/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:40:43 by takwak            #+#    #+#             */
/*   Updated: 2024/11/17 20:13:38 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_x_line(t_data *img, t_point **map)
{
	int	i;
	int	j;

	i = 1;
	while (i <= map[0]->y)
	{
		j = 1;
		while (j < map[0]->x)
		{
			if (map[i][j].x < map[i][j + 1].x)
				render_line_bresenham(img, map[i][j], map[i][j + 1]);
			else
				render_line_bresenham(img, map[i][j + 1], map[i][j]);
			j++;
		}
		i++;
	}
}

void	render_y_line(t_data *img, t_point **map)
{
	int	i;
	int	j;

	i = 1;
	while (i <= map[0]->x)
	{
		j = map[0]->y;
		while (j > 1)
		{
			if (map[j][i].x < map[j - 1][i].x)
				render_line_bresenham(img, map[j][i], map[j - 1][i]);
			else
				render_line_bresenham(img, map[j - 1][i], map[j][i]);
			j--;
		}
		i++;
	}
}
