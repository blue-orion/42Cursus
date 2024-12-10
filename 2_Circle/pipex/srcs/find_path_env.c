/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:50:10 by takwak            #+#    #+#             */
/*   Updated: 2024/12/10 23:09:57 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	**find_path(char **env)
{
	while (env)
	{
		if (!ft_strncmp(*env, "PATH=", 5))
		{
			*env += 5;
			break ;
		}
		env++;
	}
	return (ft_split(*env, ':'));
}
