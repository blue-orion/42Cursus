/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:31:31 by takwak            #+#    #+#             */
/*   Updated: 2024/12/13 02:50:34 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>
#define END 0
#define S_QUOTE 1
#define D_QUOTE 2
#define SPACE 3

int	find_split_point(char *cmd)
{
	char	*space;
	char	*single_quote;
	char	*double_quote;
	long	min;

	space = ft_strchr(cmd, ' ');
	single_quote = ft_strchr(cmd, '\'');
	double_quote = ft_strchr(cmd, '\"');
	min = LONG_MAX;
	if (space && (long)space < min)
		min = (long)space;
	if (single_quote && (long)single_quote < min)
		min = (long)single_quote;
	if (double_quote && (long)double_quote < min)
		min = (long)double_quote;
	if (min == (long)space)
		return (SPACE);
	if (min == (long)single_quote)
		return (S_QUOTE);
	if (min == (long)double_quote)
		return (D_QUOTE);
	return (END);
}

char	*split_by(int point, char **str)
{
	char	*p;
	char	*res;

	if (point == S_QUOTE)
	{
		p = ft_strchr(*str, '\'');
		res = ft_substr(p, 1, ft_strchr(p + 1, '\'') - p - 1);
		*str = ft_strchr(p + 1, '\'') + 1;
	}
	if (point == D_QUOTE)
	{
		p = ft_strchr(*str, '\"');
		res = ft_substr(p, 0, ft_strchr(p + 1, '\"') - p + 1);
		*str = ft_strchr(p + 1, '\"') + 1;
	}
	if (point == SPACE)
	{
		p = ft_strchr(*str, ' ');
		res = ft_substr(*str, 0, p - *str);
		*str = p;
	}
	return (res);
}

t_list	*split_tolist(char *cmd)
{
	t_list	*lst;
	char	*part;
	int		point;

	lst = NULL;
	while (*cmd)
	{
		while (*cmd == ' ')
			cmd++;
		if (!*cmd)
			break ;
		point = find_split_point(cmd);
		if (point != END)
			part = split_by(point, &cmd);
		if (point == END)
		{
			part = ft_strdup(cmd);
			cmd = ft_strchr(cmd, '\0');
		}
		if (!part)
			return (ft_lstclear(&lst, free), NULL);
		if (!lst_add_back(&lst, part))
			return (NULL);
	}
	return (lst);
}

char	**split_command(char *cmd)
{
	t_list	*lst;
	t_list	*cur;
	char	**split_cmd;
	int		i;

	lst = split_tolist(cmd);
	if (!lst)
		return (NULL);
	split_cmd = (char **)ft_calloc((ft_lstsize(lst) + 1), sizeof(char *));
	if (!split_cmd)
		return (ft_lstclear(&lst, free), NULL);
	i = 0;
	cur = lst;
	while (i < ft_lstsize(lst))
	{
		split_cmd[i] = ft_strdup((char *)cur->content);
		if (!split_cmd[i])
			return (ft_lstclear(&lst, free), free_twoptr((void **)split_cmd));
		cur = cur->next;
		i++;
	}
	split_cmd[i] = NULL;
	ft_lstclear(&lst, free);
	return (split_cmd);
}
