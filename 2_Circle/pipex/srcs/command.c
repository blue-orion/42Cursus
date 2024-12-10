/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:49:39 by takwak            #+#    #+#             */
/*   Updated: 2024/12/10 01:49:39 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	exe_cmd(char *path, char **cmd)
{
	if (execve(path, cmd, NULL) == -1)
		ft_exit("failed execve cmd");
}
