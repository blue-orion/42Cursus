/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 01:43:58 by takwak            #+#    #+#             */
/*   Updated: 2024/12/10 23:45:29 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int main(int argc, char **argv, char **env)
{
	t_proc	*pr;
	int		input_fd;
	int		output_fd;

	pr = save_info(argc, argv, env);
	if (argc < 5)
		ft_exit("too few arguments");
	input_fd = open(argv[1], O_RDONLY);
	output_fd = open(argv[4], O_WRONLY);
	if (input_fd == -1 || output_fd == -1)
		ft_exit("open error ");
	if (pipe(pr->p1) == -1)
		ft_exit("pipe error ");
	pr->pid = fork();
	if (pr->pid == -1)
		ft_exit("fork error ");
	if (pr->pid == 0)
	{
		dup2(input_fd, 0);
		dup2(pr->p1[1], 1);
		close(input_fd);
		close(pr->p1[0]);
		close(pr->p1[1]);
		pr->cmd_path = validate_cmd(ft_split(argv[2], ' '), pr->env_path);
		if (!pr->cmd_path)
			ft_exit("cmd error: ");
		printf("in child\n");
		if (execve(pr->cmd_path, ft_split(argv[2], ' '), NULL) == -1)
			ft_exit("execve error: ");
	}
	else
	{
		wait(&(pr->status));
		dup2(pr->p1[0], 0);
		dup2(output_fd, 1);
		close(input_fd);
		close(output_fd);
		close(pr->p1[0]);
		close(pr->p1[1]);
		printf("in parent\n");
		pr->cmd_path = validate_cmd(ft_split(argv[3], ' '), pr->env_path);
		if (!pr->cmd_path)
			ft_exit("cmd error: ");
		if (execve(pr->cmd_path, ft_split(argv[3], ' '), NULL) == -1)
			ft_exit("execve error: ");
	}
	return (0);
}
