#include <stdlib.h>
#include <unistd.h>

int	ft_exec(char *argv[], int i, char *env[])
{
	argv[i] = NULL;

	execve(argv[0], argv, env);
	return (1);
}

int	main(int argc, char *argv[], char *envp[])
{
	(void) argc;
	int	i;
	int	pid;
	int fd[2];
	int	tmp_fd;

	tmp_fd = dup(STDIN_FILENO);
	i = 0;
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|")) //iterate args
			++i;
		if (argv == &argv[i])
			continue ;
		if (argv[i] == NULL || (argv[i] && !strcmp(argv[i], ";"))) //stdout
		{
			pid = fork();
			if (pid == -1)
			{
			}
			else if (pid == 0)
			{
					
			}
			else
			{
				waitpid(pid);
			}
		}
		else if (strcmp(argv[i], "|")) //pipe
		{

		}
	}
	return (0);
}
