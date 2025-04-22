/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:10:23 by takwak            #+#    #+#             */
/*   Updated: 2025/04/22 15:10:23 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "structures.h"
# include "mlx_structure.h"

t_vec3      vec3(double x, double y, double z);
t_point3    point3(double x, double y, double z);
t_point3    color3(double r, double g, double b);
void        vset(t_vec3 *vec, double x, double y, double z);
double      vlength2(t_vec3 vec);
double      vlength(t_vec3 vec);
t_vec3      vplus(t_vec3 vec, t_vec3 vec2);
t_vec3      vplus_(t_vec3 vec, double x, double y, double z);
t_vec3      vminus(t_vec3 vec, t_vec3 vec2);
t_vec3      vminus_(t_vec3 vec, double x, double y, double z);
t_vec3      vmult(t_vec3 vec, double t);
t_vec3      vmult_(t_vec3 vec, t_vec3 vec2);
t_vec3      vdivide(t_vec3 vec, double t);
double      vdot(t_vec3 vec, t_vec3 vec2);
t_vec3      vcross(t_vec3 vec, t_vec3 vec2);
t_vec3      vunit(t_vec3 vec);
t_vec3      vmin(t_vec3 vec1, t_vec3 vec2);

void		oadd(t_object **list, t_object *new_object);
t_object	*olast(t_object *list);

void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);
void		save_line_info(t_scene *scene, char *line);
#endif
