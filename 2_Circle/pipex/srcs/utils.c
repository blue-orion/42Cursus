/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:13:14 by takwak            #+#    #+#             */
/*   Updated: 2024/12/12 02:23:10 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	**copy_argv(int argc, char **argv)
{
	char	**cmd;
	int		i;

	cmd = (char **)malloc(sizeof(char *) * (argc - 3));
	if (!cmd)
		return (NULL);
	i = 0;
	while (i < argc - 3)
	{
		cmd[i] = ft_strdup(argv[i + 2]);
		if (!cmd[i])
			return (ft_free_twoptr((void **)cmd, i));
		i++;
	}
	return (cmd);
}

t_proc	*save_info(int argc, char **argv, char **env)
{
	t_proc	*pr;

	pr = (t_proc *)malloc(sizeof(t_proc));
	pr->cmd = copy_argv(argc, argv);
	if (!pr->cmd)
		ft_exit(pr, "failed malloc in copy_argv", 0);
	pr->env_path = find_path(env);
	if (!pr->env_path)
		ft_exit(pr, "Cannot find env_path", 0);
	return (pr);
}

void	ft_exit(t_proc *pr, char *errstr, int flag)
{
	free_proc(pr);
	if (flag == 0)
		write(2, errstr, ft_strlen(errstr));
	else
		perror(errstr);
	exit(EXIT_FAILURE);
}
