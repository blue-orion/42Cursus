/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:18:02 by takwak            #+#    #+#             */
/*   Updated: 2024/12/10 23:23:44 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <libft.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct	s_proc
{
	pid_t	pid;
	int		p1[2];
	int		p2[2];
	int		status;
	char	**env_path;
	char	*cmd_path;
}	t_proc;
//Input
char	*read_data(int fd);

//Output

//path
char	**find_path(char **env);
//Exe Command
char	*validate_cmd(char **cmd, char **path);
int		child_process(t_proc *pr, char **argv);
int		parent_process(t_proc *pr, char **argv);

//Utils
void	ft_exit(char *errstr);
t_proc	*save_info(int argc, char **argv, char **env);
#endif
