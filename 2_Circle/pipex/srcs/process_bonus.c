/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 02:58:19 by takwak            #+#    #+#             */
/*   Updated: 2024/12/13 02:49:17 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

void	child_process(t_pipex *info, char **argv, char **env)
{
	close(info->p1[1]);
	info->split_cmd = split_command(argv[info->count]);
	if (!info->split_cmd)
		ft_exit(info, "split_command\n", 0);
	if (info->here_doc && info->count == 1)
		exec_here_doc_cmd(info->split_cmd, info, env);
	if (!info->here_doc && info->count == 1)
		exec_first_cmd(argv[0], info->split_cmd, info, env);
	if (info->count > 0 && info->count < info->cmd_num)
		exec_middle_cmd(info->split_cmd, info, env);
	if (info->count == info->cmd_num)
		exec_last_cmd(argv[info->cmd_num + 1], info->split_cmd, info, env);
}

void	parent_process(t_pipex *info, char **argv)
{
	if (!info->here_doc || info->count != 1)
		close(info->p1[1]);
	if (info->here_doc && info->count == 1)
		here_doc_input(argv[0], info);
	else
		info->pid = wait(&info->status);
	close(info->p1[0]);
	swap_pipe(info->p1, info->p2);
}
