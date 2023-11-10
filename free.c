#include "shell.h"

/**
 *freeCommands - Free command structures.
 *@global: arg 1.
 */
void    freeCommands(global_t *global)
{
	command_t	*tmp = global->commands, *tmp2;
	char		**str;
	int			i;

	while (tmp)
	{
		i = 0;
		tmp2 = tmp->next;
		free(tmp->path);
		free(tmp->tmp);
		str = tmp->args;
		while (str && str[i])
			free(str[i++]);
		free(str);
		free(tmp);
		tmp = tmp2;
	}
	global->commands = NULL;
}
/**
 *freeAlias - Free alias structures.
 *@global: arg 1.
 */
void    freeAlias(global_t *global)
{
	alias_t	*tmp = global->alias, *tmp2;

	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
		tmp = tmp2;
	}
	global->alias = NULL;
}
/**
 *freeEnv - Free env structures.
 *@global: arg 1.
 */
void    freeEnv(global_t *global)
{
	env_t	*tmp = global->env, *tmp2;

	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
		tmp = tmp2;
	}
	global->env = NULL;
}

/**
 * freeAll - free all.
 * @global: arg 1.
 */
void freeAll(global_t *global)
{
	free_commands(global);
	free_env(global);
	free_alias(global);
	free(global->cmd);
	free(global->left);
	close(global->fd);
	free(global);
}
