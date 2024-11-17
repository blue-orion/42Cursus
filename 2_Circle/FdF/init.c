/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:28:26 by takwak            #+#    #+#             */
/*   Updated: 2024/11/17 23:19:56 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_point(t_point *point)
{
	point->x = 0;
	point->y = 0;
	point->z = 0;
	point->t = 0;
	point->r = 255;
	point->g = 255;
	point->b = 255;
}

int	init_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "takwak");
	vars->img.img = NULL;
	vars->src_map = NULL;
	vars->scale = 0;
	vars->press_flag = 0;
	vars->px = 0;
	vars->py = 0;
	vars->projection = "isometric";
	return (1);
}

t_point	**make_map(t_point *info)
{
	int		i;
	int		j;
	t_point	**map;

	map = (t_point **)malloc(sizeof(t_point *) * ((int)info->y + 1));
	if (map == NULL)
		return (NULL);
	map[0] = (t_point *)malloc(sizeof(t_point));
	if (map[0] == NULL)
		return (free_twoptr((void **)map, 1));
	map[0][0].x = info->x;
	map[0][0].y = info->y;
	i = 1;
	while (i < info->y + 1)
	{
		map[i] = (t_point *)malloc(sizeof(t_point) * ((int)info->x + 1));
		if (map[i] == NULL)
			return (free_twoptr((void **)map, i + 1));
		j = 0;
		while (j < info->x + 1)
			init_point(&map[i][j++]);
		i++;
	}
	return (map);
}
