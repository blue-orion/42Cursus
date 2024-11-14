/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:25:18 by takwak            #+#    #+#             */
/*   Updated: 2024/11/13 20:52:28 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	win_close(int keycode, t_vars *vars)
{
	printf("you press : %d\n", (unsigned char)keycode);
	if ((unsigned char)keycode == 27)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_data	img;
	t_point	**matrix;

	if (argc == 1)
		ft_perror("Invalid input\n");
	matrix = read_file(argv[1]);
	print_matrix(matrix);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "takwak");
	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img.adr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	make_isometric_img(matrix, &vars);
	mlx_key_hook(vars.win, win_close, &vars);
	mlx_loop(vars.mlx);
	free_twoptr((void **)matrix, matrix[0]->y + 1);
}
