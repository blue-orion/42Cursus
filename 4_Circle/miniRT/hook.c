/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:05:20 by takwak            #+#    #+#             */
/*   Updated: 2025/04/14 22:05:20 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	end_program(int keycode, t_mlx *vars)
{
	exit(1);
}

int	key_hook(int keycode, t_mlx *vars)
{
	printf("keycode = %d\n", (char)keycode);
	if ((char)keycode == 27)
		end_program(keycode, vars);
}
