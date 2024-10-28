/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:59:47 by takwak            #+#    #+#             */
/*   Updated: 2024/10/28 18:26:55 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "get_next_line.h"

static char	*make_line(char *res, t_buf_bonus *info, int size)
{
	char	*new_res;
	char	*dup_s;

	if (res == NULL)
	{
		new_res = ft_strndup(info->buf, size);
		if (new_res == NULL)
			return (NULL);
	}
	else
	{
		dup_s = ft_strndup(info->buf, size);
		new_res = ft_strjoin(res, dup_s);
		free(res);
		free(dup_s);
		if (new_res == NULL)
			return (NULL);
	}
	return (new_res);
}

static int	exist_line(char **res, t_buf_bonus *info)
{
	int	len;
	char	*start_adr;

	start_adr = info->buf + info->idx;
	if (info->last)
	{
		if (ft_strchr(start_adr, '\n') != NULL)
		{
			len = ft_strchr(start_adr, '\n') + 1 - start_adr;
			*res = make_line(*res, info, len);
			start_adr += len;
			if (*(start_adr) == '\0')
			{
				info->last = 0;
				info->idx = 0;
			}
			return (1);
		}
		else
		{
			*res = make_line(*res, info, ft_strlen(start_adr));
			info->last = 0;
			info->idx = 0;
		}
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_buf_bonus	*info;
	t_buf_bonus			*list;
	char			*res;
	int				read_size;

	if (fd < 0)
		return (NULL);
	res = NULL;
	if (info == NULL)
		info = ft_newlst(info, list, fd);
	list = info;
	while (list != NULL && list->label != fd)
		list = list->next;
	if (list == NULL)
		list = ft_newlst(info, list, fd);
	printf("\ncur list : %s\n", list->buf);
	if (exist_line(&res, list))
		return (res);
	read_size = read(fd, list->buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		list->idx = 0;
		list->last = 1;
		if (read_size < BUFFER_SIZE)
			list->buf[read_size] = '\0';
		if (exist_line(&res, list))
			return (res);
		read_size = read(fd, info->buf, BUFFER_SIZE);
	}
	if (read_size == -1)
		return (free_lst(&info, &res));
	if (res != NULL)
		return (res);
	return (free_lst(&info, &res));
}
