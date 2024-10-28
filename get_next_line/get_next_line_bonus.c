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

static char	*make_line(char *res, char *buf, int size)
{
	char	*new_res;
	char	*dup_s;

	if (res == NULL)
	{
		new_res = ft_strndup(buf, size);
		if (new_res == NULL)
			return (NULL);
	}
	else
	{
		dup_s = ft_strndup(buf, size);
		new_res = ft_strjoin(res, dup_s);
		free(res);
		free(dup_s);
		if (new_res == NULL)
			return (NULL);
	}
	return (new_res);
}

static int	exist_line(char **res, t_buf *info)
{
	int	len;

	if (info->last != 0)
	{
		// 여기서 부터 고쳐야됨
		if (ft_strchr(buf + *idx, '\n') != NULL)
		{
			len = ft_strchr(buf + *idx, '\n') + 1 - (buf + *idx);
			*res = make_line(*res, buf + *idx, len);
			*idx += len;
			if (*(buf + *idx) == '\0')
			{
				*last_flag = 0;
				*idx = 0;
			}
			return (1);
		}
		else
		{
			*res = make_line(*res, buf + *idx, ft_strlen(buf + *idx));
			*idx = 0;
			*last_flag = 0;
			return (0);
		}
	}
	return (0);
}
char	*get_next_line(int fd)
{
	static t_buf	*info;
	t_buf			*list;
	char			*res;
	char			*buf;
	int				read_size;

	res = NULL;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	list = info;
	while (list->label != 0 && list->label != fd)
		list = list->next;
	if (exist_line(&res, list))
	 	return (res);
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		
	}
}
