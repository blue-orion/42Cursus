/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 23:06:20 by takwak            #+#    #+#             */
/*   Updated: 2024/11/13 23:07:58 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_twoptr(void **ptr, int y_num)
{
	int	i;

	i = 0;
	while (i < y_num)
		free(ptr[i++]);
	free(ptr);
}

int	ft_is_base(char c, char *base)
{
	int	idx;

	idx = 0;
	while (base[idx])
	{
		if (ft_toupper(c) == ft_toupper(base[idx]))
			return (idx);
		idx++;
	}
	return (-1);
}

int	ft_atoi_base(char const *s, char *base)
{
	int	idx;
	int	sign;
	int	base_len;
	int	result;

	if (s == NULL)
		return (0);
	idx = 0;
	sign = 1;
	result = 0;
	base_len = ft_strlen(base);
	while (ft_isblank(s[idx]))
		idx++;
	if (s[idx] == '-' || s[idx] == '+')
	{
		if (s[idx] == '-')
			sign = -1;
		idx++;
	}
	while (ft_is_base(s[idx], base) != -1)
	{
		result = result * base_len + ft_is_base(s[idx], base);
		idx++;
	}
	return (sign * result);
}
