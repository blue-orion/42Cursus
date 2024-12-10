/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:22:34 by takwak            #+#    #+#             */
/*   Updated: 2024/12/10 20:31:11 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	child_process(t_proc *pr, char **argv)
{
	int	input_fd;

	input_fd = open(argv[1], O_RDONLY);
	dup2(input_fd, 0);
	dup2(pr->p1[1], 1);
	close(input_fd);
	close(pr->p1[0]);
	close(pr->p1[1]);
	pr->cmd_path = validate_cmd(ft_split(argv[2], ' '), pr->env_path);
	if (!pr->cmd_path)
		ft_exit("cmd error: ");
	if (execve(pr->cmd_path, ft_split(argv[2], ' '), NULL) == -1)
		ft_exit("execve error: ");
	return (0);
}
