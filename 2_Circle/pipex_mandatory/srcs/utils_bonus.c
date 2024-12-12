/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:35:49 by takwak            #+#    #+#             */
/*   Updated: 2024/12/13 02:51:27 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

void	swap_pipe(int p1[2], int p2[2])
{
	int	i;
	int	tmp;

	i = 0;
	while (i < 2)
	{
		tmp = p1[i];
		p1[i] = p2[i];
		p2[i] = tmp;
		i++;
	}
}

void	ft_exit(t_pipex *info, char *errstr, int flag)
{
	if (flag)
		perror(errstr);
	else
		write(2, errstr, ft_strlen(errstr));
	free_twoptr((void **)info->split_cmd);
	free(info);
	exit(EXIT_FAILURE);
}

void	command_not_found(t_pipex *info, char *path, char **split_cmd)
{
	write(2, "zsh: command not found: ", 24);
	write(2, split_cmd[0], ft_strlen(split_cmd[0]));
	write(2, "\n", 1);
	free(info);
	free(path);
	free_twoptr((void **)split_cmd);
	exit(EXIT_FAILURE);
}

int	lst_add_back(t_list **lst, char *part)
{
	t_list	*new;

	new = ft_lstnew((void *)part);
	if (!new)
		return (free(part), ft_lstclear(lst, free), 0);
	ft_lstadd_back(lst, new);
	return (1);
}
