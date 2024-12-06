//Have to Input Header

#include "push_swap.h"

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

void	data_load(t_ps *st, int argc, char **argv)
{
	char	**splited;
	int		*tmp;
	int		i;
	int		split_idx;

	st->size = count_data(argc, argv);
	st->a = (int *)ft_calloc(st->size + 1, sizeof(int));
	st->b = (int *)ft_calloc(st->size + 1, sizeof(int));
	tmp = (int *)ft_calloc(st->size + 1, sizeof(int));
	i = 1;
	while (i < argc)
	{
		split_idx = 0;
		splited = ft_split(argv[i], ' ');
		while (splited[split_idx])
		{
			st->a[++(st->a_idx)] = ft_atoi(splited[split_idx]);
			tmp[st->a_idx] = ft_atoi(splited[split_idx++]);
		}
		free_twoptr((void **)splited, split_idx);
		i++;
	}
	ft_reverse(st->a, st->size);
	merge_sort(tmp, st->b, 1, st->size);
	free(tmp);
}
