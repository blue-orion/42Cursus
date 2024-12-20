/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 01:43:58 by takwak            #+#    #+#             */
/*   Updated: 2024/12/13 02:36:34 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

int main(int argc, char **argv, char **env) {
  t_pipex *info;

  if (argc < 5)
    return (0);
  info = (t_pipex *)malloc(sizeof(t_pipex));
  if (!info)
    return (0);
  judge_mode(info, argc, &argv);
  if (pipe(info->p1) == -1)
    ft_exit(info, "pipe", errno);
  info->count = 0;
  while (++info->count <= info->cmd_num) {
    if (pipe(info->p2) == -1)
      ft_exit(info, "pipe", errno);
    info->pid = fork();
    if (info->pid == -1)
      ft_exit(info, "fork", errno);
    if (info->pid == 0)
      child_process(info, argv, env);
    else
      parent_process(info, argv);
  }
  return (free(info), 0);
}
