/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:06:27 by takwak            #+#    #+#             */
/*   Updated: 2024/11/17 21:14:34 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	validate_file_name(char *file)
{
	char	*name;

	name = ft_strchr(file, '.');
	if (name == NULL)
		return (0);
	return (ft_strncmp(name, ".fdf", 5));
}
