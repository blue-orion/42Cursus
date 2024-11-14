/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:19:10 by takwak            #+#    #+#             */
/*   Updated: 2024/11/14 22:37:51 by takwak           ###   ########.fr       */
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
# define BUFFER_SIZE 10
# define WIDTH 1200
# define HEIGHT 1000

//Use mlx
typedef struct s_data
{
	void	*img;
	char	*adr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

//ComputerGraphics
typedef struct s_point
{
	double		x;
	double		y;
	double		z;
	int		t;
	int		r;
	int		g;
	int		b;
}	t_point;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;
}	t_pixel;

void	trans(t_point *point);
//Math
void	calculate_isometric(t_point **matrix);
void	trans_matrix(t_point *matrix, char axis, double theta);
void	make_isometric_img(t_point **matrix, t_vars *s);
int		create_trgb(t_point point);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	make_max_size(t_point **matrix);
void	move_center(t_point **matrix);

int		discriminant(double m, int f, t_pixel p1, t_pixel t2);
void	data_preprocess(t_pixel *dst, t_point src);
void	render_line_bresenham(t_data *img, t_point start, t_point end);

//Init utils
void	init_point(t_point *point);
t_point	**make_matrix(t_point *info);

//File
void	save_color(t_point *point, char *color_data);
t_point	**read_file(char *filename);
void	count_points(int fd, t_point *info, t_list **begin_list);
t_point	**save_to_matrix(t_list *start_data, t_point *info);

//Utils
void	ft_perror(char	*str);
void	free_twoptr(void **ptr, int y_num);
int		ft_atoi_base(char const *s, char *base);
int		ft_is_base(char c, char *base);

//Debugging
void	print_matrix(t_point **matrix);
#endif
