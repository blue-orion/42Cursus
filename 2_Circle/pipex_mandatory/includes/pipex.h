/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:18:02 by takwak            #+#    #+#             */
/*   Updated: 2024/12/12 02:24:01 by takwak           ###   ########.fr       */
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
# include <errno.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_proc
{
	pid_t	pid;
	int		p1[2];
	int		p2[2];
	int		status;
	char	**cmd;
	char	**env_path;
	char	*cmd_path;
}	t_proc;
//Input

//Output

//path
char	**find_path(char **env);

//Command
t_list	*make_list(char *cmd);
char	**ft_split_cmd(char *input_cmd);
char	*validate_cmd(char **split_cmd, char **path);
int		child_process(t_proc *pr, char **argv);
int		parent_process(t_proc *pr, char **argv);

//Utils
void	*ft_split_error(void **splited, int size);
void	ft_exit(t_proc *pr, char *errstr, int flag);
t_proc	*save_info(int argc, char **argv, char **env);

//Free
void	*error_in_list(char *cmd, t_list **start);
void	free_proc(t_proc *pr);
void	*ft_free_twoptr(void **ptr, int size);
//Debugging
void	print_command(char **cmd);
#endif
