/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:37:20 by takwak            #+#    #+#             */
/*   Updated: 2024/11/17 20:50:24 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_center(t_point **map)
{
	int	*mx;
	int	*my;
	int	i;
	int	j;

	mx = search_width(map);
	my = search_height(map);
	i = 1;
	while (i <= map[0]->y)
	{
		j = 1;
		while (j <= map[0]->x)
		{
			map[i][j].x += abs(mx[1]) + (WIDTH - mx[0]) / 2;
			map[i][j].y += abs(my[1]) + (HEIGHT - my[0]) / 2;
			j++;
		}
		i++;
	}
	free(mx);
	free(my);
}

void	move_init(t_point **map)
{
	int	*mx;
	int	*my;
	int	i;
	int	j;

	mx = search_width(map);
	my = search_height(map);
	i = 1;
	while (i <= map[0]->y)
	{
		j = 1;
		while (j <= map[0]->x)
		{
			map[i][j].x -= abs(mx[1]) + (WIDTH - mx[0]) / 2;
			map[i][j].y -= abs(my[1]) + (HEIGHT - my[0]) / 2;
			j++;
		}
		i++;
	}
	free(mx);
	free(my);
}

void	translate_map(t_point **map, int axis, int d)
{
	int	i;
	int	j;

	i = 1;
	while (i <= map[0]->y)
	{
		j = 1;
		while (j <= map[0]->x)
		{
			if (axis == 'x')
				map[i][j].x += d;
			if (axis == 'y')
				map[i][j].y += d;
			j++;
		}
		i++;
	}
}
