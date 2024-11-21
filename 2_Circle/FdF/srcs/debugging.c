/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:17:49 by takwak            #+#    #+#             */
/*   Updated: 2024/11/18 01:35:44 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	print_map(t_point **map)
{
	int	i;
	int	j;

	printf("info : x = %.2f y = %.2f\n", (*map)->x, (*map)->y);
	printf("info : x = %.2f y = %.2f\n", map[0]->x, map[0]->y);
	i = 1;
	while (i <= map[0]->y)
	{
		j = 1;
		while (j <= map[0]->x)
		{
			printf("(%.2f, %.2f, ", map[i][j].x, map[i][j].y);
			printf("%.2f)\n", map[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_lst(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		printf("%d : %s\n", i, (char *)lst->content);
		lst = lst->next;
		i++;
	}
}
