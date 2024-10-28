/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 00:11:00 by takwak            #+#    #+#             */
/*   Updated: 2024/10/29 00:11:00 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_buf_bonus	*ft_newlst(t_buf_bonus *list, t_buf_bonus *new, int fd)
{
	t_buf_bonus	*cur;

	cur = list;
	if (cur == NULL)
	{
		cur = (t_buf_bonus *)malloc(sizeof(t_buf_bonus));
		cur->label = fd;
		cur->buf[BUFFER_SIZE] = '\0';
		cur->last = 0;
		cur->idx = 0;
		cur->next = NULL;
		return (cur);
	}
	while (cur->next != NULL)
		cur = cur->next;
	new = (t_buf_bonus *)malloc(sizeof(t_buf_bonus));
	new->label = fd;
	new->buf[BUFFER_SIZE] = '\0';
	new->last = 0;
	new->idx = 0;
	new->next = NULL;
	cur->next = new;
	return (new);
}

void	*free_lst(t_buf_bonus **lst, char **res)
{
	t_buf_bonus	*cur;
	t_buf_bonus	*past;

	cur = *lst;
	while (cur != NULL)
	{
		past = cur;
		cur = cur->next;
		free(past);
	}
	*lst = cur;
	if (*res != NULL)
		free(*res);
	return (NULL);
}
