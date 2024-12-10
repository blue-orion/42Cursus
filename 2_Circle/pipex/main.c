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

	if (argc < 5)
		ft_exit("too few arguments");
	pr = save_info(argc, argv, env);
	if (pipe(pr->p1) == -1)
		ft_exit("pipe error ");
	pr->pid = fork();
	if (pr->pid == -1)
		ft_exit("fork error ");
	if (pr->pid == 0)
		child_process(pr, argv);
	else
	{
		wait(&(pr->status));
		parent_process(pr, argv);
	}
	return (0);
}
