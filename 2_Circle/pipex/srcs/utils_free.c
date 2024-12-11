/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 01:58:19 by takwak            #+#    #+#             */
/*   Updated: 2024/12/12 01:58:19 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	*error_in_list(char *cmd, t_list **start)
{
	free(cmd);
	ft_lstclear(start, free);
	return (NULL);
}

void	*ft_free_twoptr(void **ptr, int size)
{
	int	i;

	i = 0;
	if (size == 0)
	{
		while (ptr[i])
		{
			free(ptr[i]);
			i++;
		}
		free(ptr);
		return (NULL);
	}
	while (i < size)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

void	free_proc(t_proc *pr)
{
	if (pr->cmd)
		ft_free_twoptr((void **)pr->cmd, 0);
	if (pr->env_path)
		ft_free_twoptr((void **)pr->env_path, 0);
	free(pr->cmd_path);
}
