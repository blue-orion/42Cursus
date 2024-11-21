/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_info_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 03:16:34 by takwak            #+#    #+#             */
/*   Updated: 2024/11/18 02:11:54 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_info_string(t_vars *s)
{
	mlx_set_font(s->mlx, s->win, "rk16");
	mlx_string_put(s->mlx, s->win, 50, 50, 0xFFFFFF, "Num 1 : Isometric image");
	mlx_string_put(s->mlx, s->win, 50, 70, 0xFFFFFF, "Num 2 : Conic image");
	mlx_string_put(s->mlx, s->win, 50, 90, 0xFFFFFF, "Arrow : Translate image");
	mlx_string_put(s->mlx, s->win, 50, 110, 0xFFFFFF, "ESC : Close window");
	mlx_string_put(s->mlx, s->win, 50, 130, 0xFFFFFF, "R : Rotate on/off");
	mlx_string_put(s->mlx, s->win, 50, 150, 0xFFFFFF,
		"Moving mouse : Rotation Image");
	mlx_string_put(s->mlx, s->win, 50, 170, 0xFFFFFF, "Scroll up : Zoom in");
	mlx_string_put(s->mlx, s->win, 50, 190, 0xFFFFFF, "Scroll down : Zoom out");
	mlx_string_put(s->mlx, s->win, 50, 210, 0xFFFFFF, "Right Click : Memo");
	if (s->rotate_flag == 1)
		mlx_string_put(s->mlx, s->win, 300, 50, 0xFFFFFF, "Rotate on");
	else
		mlx_string_put(s->mlx, s->win, 300, 50, 0xFFFFFF, "Rotate off");
}
