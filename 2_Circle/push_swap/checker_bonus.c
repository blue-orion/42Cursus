/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:50:16 by takwak            #+#    #+#             */
/*   Updated: 2024/12/07 20:16:11 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_ps	*st;

	if (argc < 2)
		return (0);
	st = (t_ps *)malloc(sizeof(t_ps));
	data_load(st, argc, argv);
	if (!validate_data(st))
		ft_exit(st, NULL);
	if (check_instruct(st))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (free_stack(st));
}
