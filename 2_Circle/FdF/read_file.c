/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:23:18 by takwak            #+#    #+#             */
/*   Updated: 2024/11/17 23:03:24 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

void	save_point_to_map(t_point *p, char *line_data, int x, int y)
{
	char	**data_split;

	data_split = ft_split(line_data, ',');
	if (data_split == NULL)
		ft_perror("Exit in ft_split\n");
	p->x = x - 1;
	p->y = y - 1;
	if (data_split[0] == NULL)
		ft_perror("Invalid map\n");
	p->z = ft_atoi(data_split[0]);
	save_color(p, data_split[1]);
	free_twoptr((void **)data_split, 2);
}

t_point	**save_data_to_map(t_list *data, t_point **map)
{
	int		i;
	int		j;
	char	**line_split;

	i = 1;
	while (i <= map[0]->y)
	{
		line_split = ft_split((char const *)data->content, ' ');
		if (line_split == NULL)
			ft_perror("Exit in ft_split\n");
		j = 1;
		while (j <= map[0]->x)
		{
			if (line_split[j - 1] == NULL)
				ft_perror("Invalid map\n");
			save_point_to_map(&map[i][j], line_split[j - 1], j, i);
			j++;
		}
		free_twoptr((void **)line_split, map[0]->x + 1);
		data = data->next;
		i++;
	}
	return (map);
}

int	count_x_points(char *line_data, t_point *info)
{
	char	**split_res;

	split_res = ft_split(line_data, ' ');
	if (split_res == NULL)
		return (0);
	while (split_res[(int)info->x] != NULL)
		info->x++;
	free_twoptr((void **)split_res, info->x + 1);
	return (1);
}

int	count_points(int fd, t_point *info, t_list **begin_list)
{
	char	*gnl_res;
	t_list	*cur;

	gnl_res = get_next_line(fd);
	if (gnl_res == NULL)
		return (0);
	*begin_list = ft_lstnew((void *)gnl_res);
	if (*begin_list == NULL)
		return (free_gnl_buf(fd));
	cur = *begin_list;
	if (count_x_points(gnl_res, info) == 0)
		return (free_gnl_buf(fd));
	while (gnl_res != NULL)
	{
		info->y++;
		gnl_res = get_next_line(fd);
		cur->next = ft_lstnew((void *)gnl_res);
		if (cur->next == NULL)
			return (free_gnl_buf(fd));
		cur = cur->next;
	}
	return (1);
}

t_point	**read_file(char *filename)
{
	int		fd;
	t_list	*file_data;
	t_point	*map_info;
	t_point	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_perror("Failed Open file\n");
	map_info = (t_point *)malloc(sizeof(t_point));
	if (map_info == NULL)
		ft_perror("Failed malloc\n");
	init_point(map_info);
	file_data = NULL;
	if (count_points(fd, map_info, &file_data) == 0)
		exit_in_read_file(map_info, &file_data);
	map = make_map(map_info);
	if (map == NULL)
		exit_in_read_file(map_info, &file_data);
	save_data_to_map(file_data, map);
	free(map_info);
	ft_lstclear(&file_data, free);
	return (map);
}
