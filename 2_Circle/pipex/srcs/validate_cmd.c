/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:23:17 by takwak            #+#    #+#             */
/*   Updated: 2024/12/10 23:46:03 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	*validate_cmd(char **cmd, char **path)
{
	char	*p_path;
	char	*n_path;

	printf("%s\n", path[0]);
	if (!cmd)
		ft_exit("empty cmd str");
	if (!access(cmd[0], X_OK))
		return (NULL);
	while (*path)
	{
		p_path = ft_strjoin(*path, "/");
		if (!p_path)
			ft_exit("failed strjoin(malloc)");
		n_path = ft_strjoin(p_path, cmd[0]);
		if (!n_path)
			ft_exit("failed strjoin(malloc)");
		free(p_path);
		if (!access(n_path, X_OK))
			return (n_path);
		path++;
	}
	return (NULL);
}
