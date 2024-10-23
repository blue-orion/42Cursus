/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flag_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:37:10 by takwak            #+#    #+#             */
/*   Updated: 2024/10/18 06:40:17 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_is_flag_space(t_printf *info)
{
	size_t	i;

	if (ft_is_valid_type(info))
	{
		i = ft_printlen_arg(info);
		while (i++ + 1 < info->width)
			if (write(1, " ", 1) == -1)
				return (ft_error("Failed writing"));
		if (info->id >= 0)
			if (write(1, " ", 1) == -1)
				return (ft_error("Failed writing"));
		i = ft_print_type(info);
		if (info->width < i)
		{
			if (info->id >= 0)
				return (i + 1);
			return (i);
		}
		return (info->width);
	}
	return (ft_default_print(info));
}
