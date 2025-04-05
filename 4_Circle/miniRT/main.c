/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:33:38 by takwak            #+#    #+#             */
/*   Updated: 2025/04/05 16:19:29 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	end_program(int key, t_mlx *vars);

int	main(void)
{
	t_mlx	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Hello world!");
	mlx_loop(vars.mlx);
	mlx_hook(vars.win, 17, 0, end_program, &vars);
}

int	end_program(int key, t_mlx *vars)
{
	printf("%d\n", key);
	exit(1);
}
