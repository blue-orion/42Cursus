/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:13:14 by takwak            #+#    #+#             */
/*   Updated: 2024/12/10 23:45:56 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <errno.h>

t_proc	*save_info(int argc, char **argv, char **env)
{
	t_proc	*pr;

	pr = (t_proc *)malloc(sizeof(t_proc));
	pr->env_path = find_path(env);
	if (!pr->env_path)
		ft_exit("Cannot find path");
	return (pr);
}

void	ft_exit(char *errstr)
{
	ft_printf("errno = %d\n", errno);
	perror(errstr);
	exit(EXIT_FAILURE);
}
