/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 01:03:06 by takwak            #+#    #+#             */
/*   Updated: 2024/12/08 01:10:48 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char *buf;

	buf = get_next_line(0);
	while (buf != NULL)
	{
		printf("%s\n", buf);
		free(buf);
		buf = get_next_line(-1);
	}
	free(buf);
}
