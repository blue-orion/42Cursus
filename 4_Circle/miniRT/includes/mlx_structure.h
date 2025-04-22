/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_structure.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 00:33:08 by takwak            #+#    #+#             */
/*   Updated: 2025/04/23 00:33:08 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_STRUCTURE_H
# define MLX_STRUCTURE_H

# include "structures.h"

typedef struct s_img
{
	void	*imgp;
	char	*adr;
	int		bpp;
	int		length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_scene	*scene;
}	t_mlx;

#endif
