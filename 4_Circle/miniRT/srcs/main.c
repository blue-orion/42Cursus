/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:40:25 by takwak            #+#    #+#             */
/*   Updated: 2025/04/22 21:03:45 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include <fcntl.h>

void	make_image(t_mlx *vars);
t_scene	*scene_init(int fd);

int	main(int argc, char **argv)
{
	t_scene	*scene;
	t_mlx	vars;
	t_img	img;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open error");
		return (0);
	}
	vars.scene = scene_init(fd);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	img.imgp = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.adr = mlx_get_data_addr(img.imgp, &img.bpp, &img.length, &img.endian);
	vars.img = &img;
	mlx_hook(vars.win, ON_DESTROY, 0, end_program, &vars);
	mlx_hook(vars.win, ON_KEYDOWN, 1L>>0, key_hook, &vars);
	make_image(&vars);
	mlx_loop(vars.mlx);
	return (0);
}

t_scene	*scene_init(int fd)
{
	t_scene		*scene;
	t_object	*world;
	t_object	*lights;
	double		ka;
	char	*line;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		save_line_info(scene, line);
		line = get_next_line(fd);
	}
	scene->canvas = canvas(WIN_WIDTH, WIN_HEIGHT);
	scene->camera = camera(&scene->canvas, point3(0, 0, 0));
	world = object(SP, sphere(point3(-2, 0, -5), 2), color3(0.5, 0, 0));
	oadd(&world, object(SP, sphere(point3(2, 0, -5), 2), color3(0, 0.5, 0)));
	oadd(&world, object(SP, sphere(point3(0, -1000, 0), 995), color3(1, 1, 1)));
	scene->world = world;
	lights = object(LIGHT_POINT, light_point(point3(0, 20, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0));
	scene->light = lights;
	ka = 0.1;
	scene->ambient = vmult(color3(1, 1, 1), ka);
	return (scene);
}

void	make_image(t_mlx *vars)
{
	int	i;
	int	j;
	double	u;
	double	v;
	t_color3	pixel_color;
	t_ray		ray;

	j = vars->scene->canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < vars->scene->canvas.width)
		{
			int	color;

			u = (double)i / (vars->scene->canvas.width - 1);
			v = (double)j / (vars->scene->canvas.height - 1);
			vars->scene->ray = ray_primary(&vars->scene->camera, u, v);
			pixel_color = ray_color(vars->scene);
			color = create_trgb(0, 255.999 * pixel_color.x, 255.999 * pixel_color.y, 255.999 * pixel_color.z);
			my_mlx_pixel_put(vars->img, i, vars->scene->canvas.height - j, color);
			write_color(pixel_color);
			i++;
		}
		--j;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->imgp, 0, 0);
}
