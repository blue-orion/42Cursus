/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:26:03 by takwak            #+#    #+#             */
/*   Updated: 2024/11/19 17:27:52 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define KEY_ESC 27
#define KEY_LEFT 81
#define KEY_UP 82
#define KEY_RIGHT 83
#define KEY_DOWN 84
#define KEY_R 114

int	key_hook(int keycode, t_vars *s)
{
	unsigned char	key;

	key = (unsigned char)keycode;
	if (key == KEY_ESC)
		close_program(s, NULL);
	if (key == KEY_LEFT)
		translate_model(s, 'x', -1);
	if (key == KEY_UP)
		translate_model(s, 'y', -1);
	if (key == KEY_RIGHT)
		translate_model(s, 'x', 1);
	if (key == KEY_DOWN)
		translate_model(s, 'y', 1);
	if (key == KEY_R)
		rotate_on_off(s);
	if (key == '1' || key == '2')
	{
		if (key == '1')
			s->projection = "isometric";
		if (key == '2')
			s->projection = "conic";
		make_image(s);
	}
	return (0);
}

int	mouse_release_hook(int button, int x, int y, t_vars *vars)
{
	char	*str;
	int		read_size;

	if (button == 1)
		vars->press_flag = 0;
	mlx_mouse_get_pos(vars->mlx, vars->win, &x, &y);
	if (button == 3 && vars->rotate_flag != 1)
	{
		str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		read_size = read(0, str, BUFFER_SIZE);
		str[read_size - 1] = '\0';
		mlx_string_put(vars->mlx, vars->win, x, y, 0xFFFFFF, str);
		free(str);
	}
	return (0);
}

int	mouse_move_hook(int x, int y, t_vars *vars)
{
	if (vars->press_flag == 1 && vars->rotate_flag == 1)
	{
		mlx_mouse_get_pos(vars->mlx, vars->win, &x, &y);
		if (x != vars->px)
			rotate_model(vars, 'y', (double)x - vars->px);
		if (y != vars->py)
			rotate_model(vars, 'x', (double)y - vars->py);
		vars->px = x;
		vars->py = y;
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == 1)
	{
		vars->press_flag = 1;
		mlx_mouse_get_pos(vars->mlx, vars->win, &x, &y);
		vars->px = x;
		vars->py = y;
	}
	if (button == 4)
		zoom(vars, ZOOMIN);
	if (button == 5)
		zoom(vars, ZOOMOUT);
	return (0);
}

int	destroy_hook(t_vars *s)
{
	close_program(s, NULL);
	return (0);
}
