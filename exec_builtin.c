#include "shell.h"

/**
 * exec_builtin - Execute built-in command if available
 * @args: Array of strings containing the command and its arguments
 * @global: Pointer to the global state structure
 * Return: 1 if the command is a built-in, ) otherwise
 */
int exec_builtin(char **args, global_t *global)
{
	char *cmd = args[0];

	if (!cmd)
		return (0);
	else if (!_strcmp("env", cmd, _strlen("env") + 1))
	{
		env(args, global);
		return (1);
	}
	else if (!_strcmp("cd", cmd, _strlen("cd") + 1))
	{
		cd(args, global);
		return (1);
	}
	else if (!_strcmp("exit", cmd, _strlen("exit") + 1))
	{
		my_exit(args, global);
		return (1);
	}
	else if (!_strcmp("setenv", cmd, _strlen("setenv") + 1))
	{
		_setenv(args, global);
		return (1);
	}
	else if (!_strcmp("unsetenv", cmd, _strlen("unsetenv") + 1))
	{
		_unsetenv(args, global);
		return (1);
	}
	else if (!_strcmp("alias", cmd, _strlen("alias") + 1))
	{
		_alias(args, global);
		return (1);
	}
	return (0);
}
