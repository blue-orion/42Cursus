/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 22:43:22 by takwak            #+#    #+#             */
/*   Updated: 2024/11/17 23:02:09 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <errno.h>

void	ft_perror(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

int	close_program(t_vars *vars, char *error)
{
	if (vars->win != NULL)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx != NULL)
	{
		mlx_loop_end(vars);
		if (vars->img.img != NULL)
			mlx_destroy_image(vars->mlx, vars->img.img);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	free_twoptr((void **)vars->map, vars->map[0]->y + 1);
	free_twoptr((void **)vars->src_map, vars->src_map[0]->y + 1);
	if (error != NULL)
		ft_perror(error);
	exit(EXIT_SUCCESS);
	return (0);
}

void	exit_in_read_file(t_point *map_info, t_list **file_data)
{
	if (map_info != NULL)
		free(map_info);
	ft_lstclear(file_data, free);
	ft_perror("Failed in reading file\n");
}
