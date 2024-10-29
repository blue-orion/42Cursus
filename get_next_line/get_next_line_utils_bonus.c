/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 00:11:00 by takwak            #+#    #+#             */
/*   Updated: 2024/10/29 18:29:18 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	init_(t_buf_bonus *list, int type)
{
	int	i;

	if (type == 1)
	{
		list->buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (list->buf == NULL)
			return (0);
		list->buf[BUFFER_SIZE] = '\0';
		list->last = 0;
		list->idx = 0;
		list->next = NULL;
	}
	else if (type == 2)
	{
		i = 0;
		while (i < BUFFER_SIZE)
			list->buf[i++] = '\0';
		list->last = 0;
		list->idx = 0;
	}
	return (1);
}

t_buf_bonus	*ft_newlst(t_buf_bonus **list, t_buf_bonus *new, int fd)
{
	t_buf_bonus	*cur;

	if (*list == NULL)
	{
		*list = (t_buf_bonus *)malloc(sizeof(t_buf_bonus));
		if (*list == NULL)
			return (NULL);
		init_(*list, 1);
		(*list)->label = fd;
		return (*list);
	}
	cur = *list;
	while (cur->next != NULL)
		cur = cur->next;
	new = (t_buf_bonus *)malloc(sizeof(t_buf_bonus));
	if (new == NULL)
		return (NULL);
	init_(new, 1);
	new->label = fd;
	cur->next = new;
	return (new);
}

void	*free_lst(t_buf_bonus **lst, int fd)
{
	t_buf_bonus	*past;
	t_buf_bonus	*cur;
	t_buf_bonus	*freed;

	cur = *lst;
	if (cur->label == fd)
	{
		freed = cur;
		*lst = cur->next;
		free(freed->buf);
		free(freed);
		return (NULL);
	}
	past = cur;
	while (cur->label != fd)
	{
		past = cur;
		cur = cur->next;
	}
	freed = cur;
	cur = cur->next;
	past->next = cur;
	free(freed->buf);
	free(freed);
	// if (res != NULL)
	// 	free(res);
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
