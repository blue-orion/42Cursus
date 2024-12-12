/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:20:05 by takwak            #+#    #+#             */
/*   Updated: 2024/12/13 02:48:21 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

char	**find_path(char **env)
{
	while (*env)
	{
		if (!ft_strncmp(*env, "PATH=", 5))
		{
			*env += 5;
			return (ft_split(*env, ':'));
		}
		env++;
	}
	return (NULL);
}

char	*find_exec_path(char *cmd, char **env)
{
	char	**path_list;
	char	*slash_path;
	char	*path;
	int		i;

	if (!access(cmd, X_OK))
		return (cmd);
	path_list = find_path(env);
	if (!path_list)
		return (NULL);
	i = -1;
	while (path_list[++i])
	{
		slash_path = ft_strjoin(path_list[i], "/");
		path = ft_strjoin(slash_path, cmd);
		free(slash_path);
		if (!access(path, X_OK))
		{
			free_twoptr((void **)path_list);
			return (path);
		}
		free(path);
	}
	free_twoptr((void **)path_list);
	return (NULL);
}
