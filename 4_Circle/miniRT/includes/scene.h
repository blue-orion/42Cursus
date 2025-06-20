/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:23:34 by takwak            #+#    #+#             */
/*   Updated: 2025/04/22 16:23:34 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "utils.h"

t_canvas	canvas(int width, int height);
t_camera	camera(t_canvas *canvas, t_point3 origin);

t_object	*object(t_object_type type, void *element, t_color3 albedo);
t_sphere	*sphere(t_point3 center, double radius);
t_light		*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio);
#endif
