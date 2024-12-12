/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 02:00:33 by takwak            #+#    #+#             */
/*   Updated: 2024/12/12 02:00:33 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	*validate_cmd(char **split_cmd, char **path)
{
	char	*p_path;
	char	*n_path;

	if (!access(split_cmd[0], X_OK))
		return (split_cmd[0]);
	while (*path)
	{
		p_path = ft_strjoin(*path, "/");
		if (!p_path)
			return (NULL);
		n_path = ft_strjoin(p_path, split_cmd[0]);
		free(p_path);
		if (!n_path)
			return (NULL);
		if (!access(n_path, X_OK))
			return (n_path);
		path++;
	}
	return (NULL);
}
