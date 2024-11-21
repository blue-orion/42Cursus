/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:19:10 by takwak            #+#    #+#             */
/*   Updated: 2024/11/18 01:36:34 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <mlx.h>
# include <math.h>
# include <libft.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# define WIDTH 1200
# define HEIGHT 1000
# define RADIAN 0.0174533
# define ZOOMIN 1.05
# define ZOOMOUT 0.95

//ComputerGraphics
typedef struct s_point
{
	double		x;
	double		y;
	double		z;
	int			t;
	int			r;
	int			g;
	int			b;
}	t_point;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;
}	t_pixel;

//Use mlx
typedef struct s_data
{
	void	*img;
	char	*adr;
	int		bpp;
	int		length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_point	**map;
	t_point	**src_map;
	double	scale;
	int		press_flag;
	int		px;
	int		py;
	char	*projection;
	int		rotate_flag;
}	t_vars;

//MLX
void	render_x_line(t_data *img, t_point **map);
void	render_y_line(t_data *img, t_point **map);
void	trans_map(t_point *map, char axis, double theta);
double	get_scale(t_point **map);
void	move_center(t_point **map);

//Translation map
void	translate_model(t_vars *s, int axis, int d);
void	translate_map(t_point **map, int axis, int d);

//Isometric
void	calculate_isometric(t_point **map);
void	make_isometric_image(t_vars *s);
void	rotate_isometric(t_point *point);

//Conic
void	calculate_conic(t_point *p);
void	conic_projection(t_point **map);
void	make_conic_image(t_vars *s);

//Bresenham
int		plus_discriminant(double m, int f, t_pixel p1, t_pixel p2);
int		minus_discriminant(double m, int f, t_pixel p1, t_pixel p2);
void	plus_lean_more_one(double m, t_data *img, t_pixel p1, t_pixel p2);
void	plus_lean_less_one(double m, t_data *img, t_pixel p1, t_pixel p2);
void	minus_lean_more_one(double m, t_data *img, t_pixel p1, t_pixel p2);
void	minus_lean_less_one(double m, t_data *img, t_pixel p1, t_pixel p2);
void	zero_lean(t_data *img, t_pixel p1, t_pixel p2);
void	data_preprocess(t_pixel *dst, t_point src);
void	render_line_bresenham(t_data *img, t_point start, t_point end);

//MLX utils
int		close_program(t_vars *vars, char *error);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(t_point point);
void	move_init(t_point **map);
void	make_image(t_vars *s);
void	rotate_on_off(t_vars *s);

//Init utils
void	init_point(t_point *point);
int		init_mlx(t_vars *vars);
t_point	**make_map(t_point *info);

//File
int		validate_file_name(char *file);
void	save_color(t_point *point, char *color_data);
t_point	**read_file(char *filename);
int		count_points(int fd, t_point *info, t_list **begin_list);
t_point	**save_to_map(t_list *start_data, t_point *info);

//Utils
void	ft_perror(char	*str);
void	*free_twoptr(void **ptr, int y_num);
void	exit_in_read_file(t_point *map_info, t_list **file_data);
int		free_gnl_buf(int fd);
int		ft_atoi_base(char const *s, char *base);
int		ft_is_base(char c, char *base);
int		abs(int n);
void	apply_scale(t_point **map, double scale);
void	remove_scale(t_point **map, double scale);
int		*search_height(t_point **map);
int		*search_width(t_point **map);
void	copy_matrix(t_point ***dst, t_point ***src);

//Utils vector
float	vec_len(t_point p);
t_point	*vec_norm(t_point *p);
t_point	*vec_cross(t_point *p1, t_point *p2);
t_point	*vec_sub(t_point *p1, t_point *p2);

//Zoom
void	zoom(t_vars *s, double zoom);

//Rotate
void	rotate_inverse_point(t_point *point, char axis, double theta);
void	rotate_inverse_map(t_point **point, char axis, double theta);
void	rotate_map(t_point **point, char axis, double theta);
void	rotate_point(t_point *point, char axis, double theta);
void	rotate_model(t_vars *s, char axis, double angle);

//Event_hook
int		key_hook(int keycode, t_vars *s);
int		mouse_hook(int button, int x, int y, t_vars *vars);
int		mouse_release_hook(int button, int x, int y, t_vars *vars);
int		mouse_move_hook(int x, int y, t_vars *vars);
int		destroy_hook(t_vars *s);

//Camera point
void	trans_cam_point(t_point *p, t_point *pos_cam, t_point *up, t_point src);
void	camera_map(t_point **map);
void	vec_camera(t_point *p, t_point *pos_camera, t_point *up);

//Input string
void	delete_string(t_vars *s);
void	put_info_string(t_vars *s);

//Debugging
void	print_map(t_point **map);
void	print_lst(t_list *lst);
#endif
