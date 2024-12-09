/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:03:19 by takwak            #+#    #+#             */
/*   Updated: 2024/12/10 01:26:50 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

void	ft_reverse(int *st, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	j = size;
	while (i <= size / 2)
	{
		tmp = st[i];
		st[i] = st[j];
		st[j] = tmp;
		i++;
		j--;
	}
}

int	count_data(int argc, char **argv)
{
	char	**splited;
	int		split_idx;
	int		i;
	int		cnt;

	cnt = 0;
	i = 1;
	while (i < argc)
	{
		splited = ft_split(argv[i], ' ');
		split_idx = 0;
		while (splited[split_idx])
		{
			cnt++;
			split_idx++;
		}
		free_twoptr((void **)splited, split_idx);
		i++;
	}
	return (cnt);
}

void	save_data(t_ps *st, int *tmp, char **splited, int split_idx)
{
	while (splited[split_idx])
	{
		if (str_isdigit(splited[split_idx]))
		{
			st->a[++(st->a_idx)] = ft_atoi(splited[split_idx]);
			tmp[st->a_idx] = ft_atoi(splited[split_idx]);
			if (tmp[st->a_idx] != ft_atoll(splited[split_idx]))
			{
				free_split(splited);
				ft_exit(st, tmp);
			}
			split_idx++;
		}
		else
			ft_exit(st, tmp);
	}
	free_twoptr((void **)splited, split_idx);
}

void	data_load(t_ps *st, int argc, char **argv)
{
	char	**splited;
	int		*tmp;
	int		i;
	int		split_idx;

	st->size = count_data(argc, argv);
	init_stack(st);
	tmp = (int *)ft_calloc(st->size + 1, sizeof(int));
	if (tmp == NULL)
		ft_exit(st, NULL);
	i = 0;
	while (++i < argc)
	{
		split_idx = 0;
		splited = ft_split(argv[i], ' ');
		if (splited == NULL || splited[0] == NULL)
		{
			free_split(splited);
			ft_exit(st, tmp);
		}
		save_data(st, tmp, splited, split_idx);
	}
	ft_reverse(st->a, st->size);
	merge_sort(tmp, st->b, 1, st->size);
	free(tmp);
}
