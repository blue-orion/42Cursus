/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:18:35 by takwak            #+#    #+#             */
/*   Updated: 2024/11/14 20:57:02 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_center(t_point **matrix)
{
	int	move_x;
	int	move_y;
	int	i;
	int	j;

	move_x = matrix[1][(int)matrix[0]->x].x - matrix[(int)matrix[0]->y][1].x;
	move_x = (WIDTH - move_x) / 2 + -1 * matrix[(int)matrix[0]->y][1].x;
	move_y = (HEIGHT - matrix[(int)matrix[0]->y][(int)matrix[0]->x].y) / 2;
	i = 1;
	while (i <= matrix[0]->y)
	{
		j = 1;
		while (j <= matrix[0]->x)
		{
			matrix[i][j].x += move_x;
			matrix[i][j].y += move_y;
			j++;
		}
		i++;
	}
}

void	make_max_size(t_point **matrix)
{
	int	supply_x;
	int	supply_y;
	int	scale;
	int	i;
	int	j;

	supply_x = (WIDTH / 2) / (int)matrix[0]->x;
	supply_y = (HEIGHT / 2) / (int)matrix[0]->y;
	if (supply_x < supply_y)
		scale = supply_x;
	else
		scale = supply_y;
	i = 1;
	while (i <= (int)matrix[0]->y)
	{
		j = 1;
		while (j <= (int)matrix[0]->x)
		{
			matrix[i][j].x *= scale;
			matrix[i][j].y *= scale;
			j++;
		}
		i++;
	}
}
