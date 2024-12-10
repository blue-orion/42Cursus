/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:41:08 by takwak            #+#    #+#             */
/*   Updated: 2024/12/10 17:11:50 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	*read_data(int fd)
{
	char	*new_data;
	char	*past_data;
	char	*line;

	// perror("block read?");
	// perror(ft_strjoin("fd = ", ft_itoa(fd)));
	// if (fd == -1)
	// 	ft_exit("failed open");
	new_data = ft_strdup("");
	if (!new_data)
		ft_exit("failed strdup(malloc)");
	line = get_next_line(fd);
	while (line)
	{
		past_data = new_data;
		new_data = ft_strjoin(past_data, line);
		if (!new_data)
			ft_exit("failed strjoin(malloc)");
		free(past_data);
		free(line);
		line = get_next_line(fd);
	}
	return (new_data);
}
