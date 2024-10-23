/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:14:29 by takwak            #+#    #+#             */
/*   Updated: 2024/10/18 02:36:42 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_width(const char *s, t_printf *info)
{
	int	move;

	move = 0;
	while (ft_isdigit(*s))
	{
		info->width = info->width * 10 + (*s - '0');
		move++;
		s++;
	}
	return (move);
}
