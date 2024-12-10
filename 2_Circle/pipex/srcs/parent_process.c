
#include <pipex.h>

int	parent_process(t_proc *pr, char **argv)
{
	int	output_fd;

	output_fd = open(argv[4], O_WRONLY);
	dup2(pr->p1[0], 0);
	dup2(output_fd, 1);
	close(output_fd);
	close(pr->p1[0]);
	close(pr->p1[1]);
	pr->cmd_path = validate_cmd(ft_split(argv[3], ' '), pr->env_path);
	if (!pr->cmd_path)
		ft_exit("cmd error: ");
	if (execve(pr->cmd_path, ft_split(argv[3], ' '), NULL) == -1)
		ft_exit("execve error: ");
}
