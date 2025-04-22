/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:36:22 by takwak            #+#    #+#             */
/*   Updated: 2025/04/05 16:11:17 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "print.h"
# include "mlx_structure.h"
# include "scene.h"
# include "trace.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WIN_WIDTH 1080
# define WIN_HEIGHT 720

enum
{
	ON_KEYDOWN = 2,
	ON_DESTROY = 17
};

#define PI 3.141592

int	end_program(int keycode, t_mlx *vars);
int	key_hook(int keycode, t_mlx *vars);
#endif
