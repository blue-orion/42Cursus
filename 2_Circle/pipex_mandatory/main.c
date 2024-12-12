/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 01:43:58 by takwak            #+#    #+#             */
/*   Updated: 2024/12/12 02:33:54 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int argc, char **argv, char **env)
{
	t_proc	*pr;

	if (argc < 5)
		return (0);
	pr = save_info(argc, argv, env);
	if (pipe(pr->p1) == -1)
		ft_exit(pr, "pipe error ", errno);
	pr->pid = fork();
	if (pr->pid == -1)
		ft_exit(pr, "fork error ", errno);
	if (pr->pid == 0)
		child_process(pr, argv);
	else
		parent_process(pr, argv);
	return (0);
}
