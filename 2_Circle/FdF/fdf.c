/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:25:18 by takwak            #+#    #+#             */
/*   Updated: 2024/11/17 22:55:40 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 1)
		ft_perror("Invalid input\n");
	if (validate_file_name(argv[1]))
		ft_perror("Invalid file name\n");
	vars.map = read_file(argv[1]);
	if (init_mlx(&vars) == 0)
	{
		free_twoptr((void **)vars.map, vars.map[0]->y + 1);
		ft_perror("Failed init mlx\n");
	}
	copy_matrix(&vars.src_map, &vars.map);
	vars.scale = get_scale(vars.map);
	make_image(&vars);
	put_info_string(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 17, 0, destroy_hook, &vars);
	mlx_hook(vars.win, 5, 1L << 3, mouse_release_hook, &vars);
	mlx_hook(vars.win, 6, 1L << 6, mouse_move_hook, &vars);
	mlx_loop(vars.mlx);
}
