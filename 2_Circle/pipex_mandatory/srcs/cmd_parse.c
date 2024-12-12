/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:49:39 by takwak            #+#    #+#             */
/*   Updated: 2024/12/12 01:18:56 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	**ft_split_cmd(char *input_cmd)
{
	char	**cmd;
	t_list	*start;
	t_list	*cur;
	int		i;

	start = make_list(input_cmd);
	if (!start)
		return (NULL);
	cmd = (char **)malloc(sizeof(char *) * (ft_lstsize(start) + 1));
	cur = start;
	i = 0;
	while (cur)
	{
		cmd[i] = ft_strdup((char *)cur->content);
		cur = cur->next;
		i++;
	}
	cmd[i] = NULL;
	ft_lstclear(&start, free);
	return (cmd);
}
