/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_line_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 00:51:20 by takwak            #+#    #+#             */
/*   Updated: 2025/04/23 00:51:20 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"
#include "../libft/libft.h"

void	replace_space_to_tab(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\t')
			s[i] = ' ';
		i++;
	}
}

void	save_ambient(t_scene *scene, char **line)
{
	char	*dot;

	dot = ft_strchr(line[1], '.');
	
}

void	save_line_info(t_scene *scene, char *line)
{
	char **splited;

	replace_space_to_tab(line);
	splited = ft_split(line, ' ');
	if (!splited)
		return ;
	if (!ft_strncmp(splited[0], "A", 2))
		save_ambient();
	if (!ft_strncmp(splited[0], "C", 2))
		save_camera();
	if (!ft_strncmp(splited[0], "L", 2))
		save_light();
	if (!ft_strncmp(splited[0], "pl", 3))
		save_object();
	if (!ft_strncmp(splited[0], "sp", 3))
		save_object();
	if (!ft_strncmp(splited[0], "cy", 3))
		save_object();
	return ;
}
