/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 00:44:10 by takwak            #+#    #+#             */
/*   Updated: 2024/12/12 02:24:29 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	child_process(t_proc *pr, char **argv)
{
	int	input_fd;

	input_fd = open(argv[1], O_RDONLY);
	if (input_fd == -1)
		ft_exit(pr, "open failed", errno);
	dup2(input_fd, 0);
	dup2(pr->p1[1], 1);
	close(input_fd);
	close(pr->p1[0]);
	close(pr->p1[1]);
	pr->cmd = ft_split_cmd(argv[2]);
	if (!pr->cmd)
		ft_exit(pr, "split failed in ft_split_cmd", 0);
	pr->cmd_path = validate_cmd(pr->cmd, pr->env_path);
	if (!pr->cmd_path)
		ft_exit(pr, "cmd error", 0);
	if (execve(pr->cmd_path, pr->cmd, NULL) == -1)
		ft_exit(pr, "execve error", errno);
	return (0);
}

int	parent_process(t_proc *pr, char **argv)
{
	int	output_fd;

	output_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
		ft_exit(pr, "open failed", errno);
	dup2(pr->p1[0], 0);
	dup2(output_fd, 1);
	close(output_fd);
	close(pr->p1[0]);
	close(pr->p1[1]);
	pr->cmd = ft_split_cmd(argv[3]);
	if (!pr->cmd)
		ft_exit(pr, "failed split in ft_split_cmd", 0);
	pr->cmd_path = validate_cmd(pr->cmd, pr->env_path);
	if (!pr->cmd_path)
		ft_exit(pr, "cmd error" , 0);
	if (execve(pr->cmd_path, pr->cmd, NULL) == -1)
		ft_exit(pr, "execve error", errno);
	return (0);
}
