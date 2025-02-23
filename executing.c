#include "shell.h"

/**
 * execBinary - executes binary.
 * @command: first argument.
 * @global: second argument.
 */

void execBinary(command_t *command, global_t *global)
{
	pid_t n;
	int m;

	if (!command->path)
	{
		printError(command->args[0], "not found", global);
		global->exit_code = 127;
	}
	else if (access(command->path, X_OK))
	{
		printError(command->args[0], "Permission denied", global);
		global->exit_code = 126;
	}
	else
	{
		n = fork();
		if (!n)
			execve(command->path, command->args, global->envp);
		else
		{
			waitpid(n, &m, 0);
			if (WIFEXITED(m))
				global->exit_code = WEXITSTATUS(m);
		}
	}
}

/**
 * exe - executes commands.
 * @global: first argument.
 */

void exe(global_t *global)
{
	command_t	*tmp = global->commands;
	char		**str;
	id_t		i = 0;

	while (tmp)
	{
		if (tmp->args)
		{
			if (!execBuiltin(tmp->args, global))
				execBinary(tmp, global);
		}
		else if (tmp->tmp)
		{
			str = the_advanced_split(tmp->tmp, global);
			exe_logical_operators(str, global);
			while (str && str[i])
				free(str[i++]);
			free(str);
		}
		tmp = tmp->next;
	}
}
