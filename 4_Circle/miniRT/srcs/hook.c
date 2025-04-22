/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:32:35 by takwak            #+#    #+#             */
/*   Updated: 2025/04/22 20:32:35 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	end_program(int keycode, t_mlx *vars)
{
	exit(1);
}

int	key_hook(int keycode, t_mlx *vars)
{
	printf("keycode = %d\n", (char)keycode);
	if ((char)keycode == 27)
		end_program(keycode, vars);
	return (0);
}
