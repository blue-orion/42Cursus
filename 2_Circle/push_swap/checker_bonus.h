/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:54:31 by takwak            #+#    #+#             */
/*   Updated: 2024/12/07 20:16:21 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		check_instruct(t_ps *st);
void	run_instruct(char *inst, t_ps *st);
#endif
