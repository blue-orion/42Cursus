/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:18:35 by takwak            #+#    #+#             */
/*   Updated: 2024/11/18 01:39:36 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <limits.h>

int	*search_width(t_point **map)
{
	int	i;
	int	j;
	int	*info;

	i = 1;
	info = (int *)malloc(sizeof(int) * 2);
	info[1] = INT_MAX;
	info[0] = INT_MIN;
	while (i <= (int)map[0]->y)
	{
		j = 1;
		while (j <= (int)map[0]->x)
		{
			if (map[i][j].x < info[1])
				info[1] = map[i][j].x;
			if (map[i][j].x > info[0])
				info[0] = map[i][j].x;
			j++;
		}
		i++;
	}
	info[0] = info[0] - info[1];
	return (info);
}

int	*search_height(t_point **map)
{
	int	i;
	int	j;
	int	*info;

	i = 1;
	info = (int *)malloc(sizeof(int) * 2);
	info[1] = INT_MAX;
	info[0] = INT_MIN;
	while (i <= (int)map[0]->y)
	{
		j = 1;
		while (j <= (int)map[0]->x)
		{
			if (map[i][j].y < info[1])
				info[1] = map[i][j].y;
			if (map[i][j].y > info[0])
				info[0] = map[i][j].y;
			j++;
		}
		i++;
	}
	info[0] = info[0] - info[1];
	return (info);
}

void	copy_matrix(t_point ***dst, t_point ***src)
{
	int	i;
	int	j;

	if (*dst == NULL)
		*dst = make_map((**src));
	(**dst)->x = (**src)->x;
	(**dst)->y = (**src)->y;
	i = 1;
	while (i <= (int)(*src)[0]->y)
	{
		j = 1;
		while (j <= (int)(*src)[0]->x)
		{
			(*dst)[i][j].x = (*src)[i][j].x;
			(*dst)[i][j].y = (*src)[i][j].y;
			(*dst)[i][j].z = (*src)[i][j].z;
			(*dst)[i][j].t = (*src)[i][j].t;
			(*dst)[i][j].r = (*src)[i][j].r;
			(*dst)[i][j].g = (*src)[i][j].g;
			(*dst)[i][j].b = (*src)[i][j].b;
			j++;
		}
		i++;
	}
}

void	save_color(t_point *point, char *color_data)
{
	int	color;

	if (color_data == NULL)
		return ;
	color = ft_atoi_base(color_data + 2, "0123456789abcdef");
	point->t = (color >> 24) & 0xFF;
	point->r = (color >> 16) & 0xFF;
	point->g = (color >> 8) & 0xFF;
	point->b = (color) & 0xFF;
}
