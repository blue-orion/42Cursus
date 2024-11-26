/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:12:51 by takwak            #+#    #+#             */
/*   Updated: 2024/11/24 23:22:24 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <libft.h>

int	main(int argc, char **argv)
{
	int	fd;
	int	num;
	int	*rand_num;
	char	*wr;

	srand(time(NULL));
	num = ft_atoi(argv[1]);
	rand_num = (int *)malloc(sizeof(int) * num);
	fd = open("rand.txt", O_WRONLY | O_CREAT | O_TRUNC);
	for (int i = 0; i < num; i++)
	{
		rand_num[i] = rand();
		for (int j = 0; j < i; j++)
		{
			while (rand_num[j] == rand_num[i])
				rand_num[i] = rand();
		}
	}
	for (int i = 0 ; i < num; i++)
	{
		wr = ft_itoa(rand_num[i]);
		write(fd, wr, ft_strlen(wr));
		write(fd, " ", 1);
	}
}
