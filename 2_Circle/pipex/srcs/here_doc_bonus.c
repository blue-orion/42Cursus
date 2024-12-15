/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 05:16:48 by takwak            #+#    #+#             */
/*   Updated: 2024/12/15 18:17:43 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

void	judge_mode(t_pipex *info, int argc, char ***argv)
{
	if (!ft_strncmp((*argv)[1], "here_doc", 9))
	{
		info->here_doc = 1;
		*argv += 2;
		info->cmd_num = argc - 4;
	}
	else
	{
		info->here_doc = 0;
		*argv += 1;
		info->cmd_num = argc - 3;
	}
}

void	here_doc_input(char *limiter, t_pipex *info)
{
	char	*line;

	limiter = ft_strjoin(limiter, "\n");
	if (!limiter)
		return ;
	write(1, "pipe heredoc> ", 14);
	line = get_next_line(0);
	while (line)
	{
		if (!ft_strncmp(line, limiter, ft_strlen(limiter) + 1))
			break ;
		write(info->p1[1], line, ft_strlen(line));
		free(line);
		write(1, "pipe heredoc> ", 14);
		line = get_next_line(0);
	}
	free(line);
	free(limiter);
	close(info->p1[1]);
}
