/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:57:22 by takwak            #+#    #+#             */
/*   Updated: 2024/12/15 17:26:11 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

void	exec_here_doc_cmd(char **split_cmd, t_pipex *info, char **env)
{
	char	*path;

	dup2(info->p1[0], 0);
	dup2(info->p2[1], 1);
	close(info->p1[1]);
	close(info->p2[1]);
	path = find_exec_path(split_cmd[0], env);
	if (!path)
		command_not_found(info, path, split_cmd);
	if (execve(path, split_cmd, env) == -1)
	{
		free(path);
		ft_exit(info, "execve", errno);
	}
}

void	exec_first_cmd(char *file, char **split_cmd, t_pipex *info, char **env)
{
	int		input_fd;
	char	*path;

	close(0);
	input_fd = open(file, O_RDONLY);
	if (input_fd == -1)
		ft_exit(info, file, errno);
	dup2(info->p2[1], 1);
	close(info->p2[1]);
	path = find_exec_path(split_cmd[0], env);
	if (!path)
		command_not_found(info, path, split_cmd);
	if (execve(path, split_cmd, env) == -1)
	{
		free(path);
		ft_exit(info, "execve", errno);
	}
}

void	exec_middle_cmd(char **split_cmd, t_pipex *info, char **env)
{
	char	*path;

	dup2(info->p1[0], 0);
	dup2(info->p2[1], 1);
	close(info->p2[1]);
	path = find_exec_path(split_cmd[0], env);
	if (!path)
		command_not_found(info, path, split_cmd);
	if (execve(path, split_cmd, env) == -1)
	{
		free(path);
		ft_exit(info, "execve", errno);
	}
}

void	exec_last_cmd(char *file, char **split_cmd, t_pipex *info, char **env)
{
	int		output_fd;
	char	*path;

	close(1);
	if (info->here_doc)
		output_fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		output_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
		ft_exit(info, file, errno);
	dup2(info->p1[0], 0);
	close(info->p2[1]);
	path = find_exec_path(split_cmd[0], env);
	if (!path)
		command_not_found(info, path, split_cmd);
	if (execve(path, split_cmd, env) == -1)
	{
		free(path);
		ft_exit(info, "execve", errno);
	}
}
