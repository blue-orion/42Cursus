/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 02:02:24 by takwak            #+#    #+#             */
/*   Updated: 2024/12/12 02:02:24 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#define QUOTE 1
#define SPACE 2

char	*add_first_node(t_list **lst, char *cmd)
{
	char	*content;

	*lst = NULL;
	if (ft_strchr(cmd, ' '))
	{
		content = ft_substr(cmd, 0, ft_strchr(cmd, ' ') - cmd);
		if (!content)
			return (error_in_list(cmd, lst));
		*lst = ft_lstnew((void *)content);
		return (ft_strchr(cmd, ' '));
	}
	content = ft_strdup(cmd);
	*lst = ft_lstnew((void *)content);
	return (ft_strchr(cmd, '\0'));
}

int	find_option(char *cmd)
{
	char	*quote;
	char	*space;

	quote = NULL;
	space = NULL;
	if (ft_strchr(cmd, '\"'))
		quote = ft_strchr(cmd, '\"');
	if (ft_strchr(cmd, '\''))
		quote = ft_strchr(cmd, '\'');
	if (ft_strchr(cmd, ' '))
		space = ft_strchr(cmd, ' ');
	if (quote && space)
	{
		if (quote < space)
			return (QUOTE);
		else
			return (SPACE);
	}
	if (quote)
		return (QUOTE);
	if (space)
		return (SPACE);
	return (0);
}

char	*quote_option(char *ptr, size_t *move)
{
	char	*start;
	char	*end;

	if (ft_strchr(ptr, '\"'))
	{
		start = ft_strchr(ptr, '\"');
		end = ft_strchr(start + 1, '\"');
		*move = end - ptr;
		ptr = ft_substr(ptr, start - ptr, end - start + 1);
		return (ptr);
	}
	else if (ft_strchr(ptr, '\''))
	{
		start = ft_strchr(ptr, '\'');
		end = ft_strchr(start + 1, '\'');
		*move = end - ptr;
		ptr = ft_substr(ptr, start + 1 - ptr, end - start - 1);
		return (ptr);
	}
	return (NULL);
}

char	*make_content(char **content, char *cmd)
{
	size_t	len;
	char	*ptr;

	if (find_option(cmd) == QUOTE)
	{
		*content = quote_option(cmd, &len);
		ptr = cmd + len + 1;
	}
	else if (find_option(cmd) == SPACE)
	{
		ptr = ft_strchr(cmd, ' ');
		len = ptr - cmd;
		*content = ft_substr(cmd, 0, len);
	}
	else
	{
		*content = ft_strdup(cmd);
		ptr = ft_strchr(cmd, '\0');
	}
	return (ptr);
}

t_list	*make_list(char *cmd)
{
	t_list	*lst;
	char	*ptr;
	char	*content;

	content = NULL;
	cmd = ft_strtrim(cmd, " ");
	if (!cmd || !*cmd)
		return (NULL);
	ptr = add_first_node(&lst, cmd);
	while (*ptr)
	{
		while (*ptr == ' ')
			ptr++;
		cmd = ptr;
		ptr = make_content(&content, cmd);
		if (!content)
			return (error_in_list(cmd, &lst));
		ft_lstadd_back(&lst, ft_lstnew((void *)content));
	}
	return (lst);
}
