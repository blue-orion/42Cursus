/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:23:18 by takwak            #+#    #+#             */
/*   Updated: 2024/11/13 21:23:07 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

void	print_lst(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		printf("%d : %s\n", i, (char *)lst->content);
		lst = lst->next;
		i++;
	}
}

void	save_color(t_point *point, char *color_data)
{
	int	color;

	if (color_data == NULL)
		return ;
	printf("%s\n", color_data);
	color = ft_atoi_base(color_data + 2, "0123456789abcdef");
	printf("%x\n", color);
	point->t = (color >> 24) & 0xFF;
	point->r = (color >> 16) & 0xFF;
	point->g = (color >> 8) & 0xFF;
	point->b = (color) & 0xFF;
	printf("t : %d | r : %d | g : %d | b : %d\n", point->t, point->r, point->g, point->b);
}

t_point	**save_data_to_matrix(t_list *data, t_point **matrix)
{
	int		i;
	int		j;
	char	**line_split;
	char	**data_split;

	i = 1;
	while (i <= matrix[0]->y)
	{ line_split = ft_split((char const *)data->content, ' ');
		if (line_split == NULL)
			ft_perror("Exit in ft_split\n");
		j = 1;
		while (j <= matrix[0]->x)
		{
			data_split = ft_split(line_split[j - 1], ',');
			if (line_split == NULL)
				ft_perror("Exit in ft_split\n");
			matrix[i][j].x = j - 1;
			matrix[i][j].y = i - 1;
			if (line_split[j - 1] == NULL || data_split[0] == NULL)
				ft_perror("Invalid matrix\n");
			matrix[i][j].z = ft_atoi(data_split[0]);
			save_color(&matrix[i][j], data_split[1]);
			free_twoptr((void **)data_split, 2);
			j++;
		}
		free_twoptr((void **)line_split, matrix[0]->x + 1);
		data = data->next;
		i++;
	}
	return (matrix);
}

void	count_points(int fd, t_point *info, t_list **begin_list)
{
	char	*gnl_res;
	char	**split_res;
	t_list	*cur;

	gnl_res = get_next_line(fd);
	if (gnl_res == NULL)
		return (ft_perror("Error or No data in file\n"));
	*begin_list = ft_lstnew((void *)gnl_res);
	cur = *begin_list;
	split_res = ft_split(gnl_res, ' ');
	if (split_res == NULL)
		return (ft_perror("Exit in ft_split\n"));
	while (split_res[(int)info->x] != NULL)
		info->x++;
	free_twoptr((void **)split_res, info->x + 1);
	while (gnl_res != NULL)
	{
		info->y++;
		gnl_res = get_next_line(fd);
		cur->next = ft_lstnew((void *)gnl_res);
		if (cur == NULL)
			return (ft_perror("Exit in ft_lstnew\n"));
		cur = cur->next;
	}
}

t_point	**read_file(char *filename)
{
	int		fd;
	t_list	*file_data;
	t_point	*matrix_info;
	t_point	**matrix;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_perror("Failed Open file\n");
	matrix_info = (t_point *)malloc(sizeof(t_point));
	init_point(matrix_info);
	file_data = NULL;
	count_points(fd, matrix_info, &file_data);
	print_lst(file_data);
	matrix = make_matrix(matrix_info);
	free(matrix_info);
	save_data_to_matrix(file_data, matrix);
	ft_lstclear(&file_data, free);
	return (matrix);
}
