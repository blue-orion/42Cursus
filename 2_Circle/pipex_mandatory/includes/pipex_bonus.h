/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:18:02 by takwak            #+#    #+#             */
/*   Updated: 2024/12/13 02:50:53 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <libft.h>
# include <errno.h>
# include <limits.h>

typedef struct s_pipex
{
	pid_t	pid;
	int		p1[2];
	int		p2[2];
	int		status;
	int		here_doc;
	int		cmd_num;
	char	**split_cmd;
	int		count;
}	t_pipex;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//Here_doc
void	judge_mode(t_pipex *info, int argc, char ***argv);
void	here_doc_input(char *limiter, t_pipex *info);

//Path
char	*find_exec_path(char *cmd, char **env);

//Process
void	child_process(t_pipex *info, char **argv, char **env);
void	parent_process(t_pipex *info, char **argv);

//Command
char	**split_command(char *cmd);
void	exec_here_doc_cmd(char **split_cmd, t_pipex *info, char **env);
void	exec_first_cmd(char *file, char **split_cmd, t_pipex *info, char **env);
void	exec_middle_cmd(char **split_cmd, t_pipex *info, char **env);
void	exec_last_cmd(char *file, char **split_cmd, t_pipex *info, char **env);

//Utils
void	swap_pipe(int p1[2], int p2[2]);
void	ft_exit(t_pipex *info, char *errstr, int flag);
void	command_not_found(t_pipex *info, char *path, char **split_cmd);
int		lst_add_back(t_list **lst, char *part);

//Free
void	*free_twoptr(void **ptr);

#endif
