/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:55:35 by takwak            #+#    #+#             */
/*   Updated: 2024/10/29 18:30:55 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_buffer
{
	int				label;
	char			*buf;
	int				idx;
	int				last;
	struct s_buffer	*next;
}	t_buffer;

t_buffer	*ft_newlst(t_buffer **list, t_buffer *new, int fd);
void		*free_lst(t_buffer **lst, int fd);
char		*ft_strchr(const char *s, int c);
int			init_(t_buffer *list, int type);
char		*get_next_line(int fd);
#endif
