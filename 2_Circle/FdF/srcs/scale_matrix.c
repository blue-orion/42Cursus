/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:38:36 by takwak            #+#    #+#             */
/*   Updated: 2024/11/16 17:08:22 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	get_scale(t_point **map)
{
	double	supply_x;
	double	supply_y;
	double	scale;

	supply_x = (WIDTH / 2) / map[0]->x;
	supply_y = (HEIGHT / 2) / map[0]->y;
	if (supply_x < supply_y)
		scale = supply_x;
	else
		scale = supply_y;
	return (scale);
}

void	apply_scale(t_point **map, double scale)
{
	int	i;
	int	j;

	i = 1;
	while (i <= (int)map[0]->y)
	{
		j = 1;
		while (j <= (int)map[0]->x)
		{
			map[i][j].x *= scale;
			map[i][j].y *= scale;
			map[i][j].z *= scale;
			j++;
		}
		i++;
	}
}

void	remove_scale(t_point **map, double scale)
{
	int	i;
	int	j;

	i = 1;
	while (i <= (int)map[0]->y)
	{
		j = 1;
		while (j <= (int)map[0]->x)
		{
			map[i][j].x /= scale;
			map[i][j].y /= scale;
			map[i][j].z /= scale;
			j++;
		}
		i++;
	}
}
