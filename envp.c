#include "shell.h"

/**
 * str_copy1 - Copies a substring from the input string
 * @str: The input string from which the substring is copied
 * @idx: A pointer to index from which copying starts
 * @a: The character at which copying stops.
 * Return: The copied substring
 */
char *str_copy1(char *str, int *idx, char a)
{
	int i, start, y;
	char *ptr;

	i = *idx;
	start = *idx;
	while (str[i] && str[i] != a)
	{
		i++;
		*idx = *idx + 1;
	}
	ptr = malloc(i + 1);
	y = 0;
	while (y < 1)
		ptr[y++] = str[start++];
	ptr[i] = '\0';
	return (ptr);
}

/**
 * init_env - Initialize the env variables
 * @envp: The arr of env var passed to the program
 * @global: A pointer to global state struct
 */
void init_env(char **envp, global_t *global)
{
	int i, idx;
	env_t *env, *head;

	i = 0;
	head = NULL;
	while (envp && envp[i])
	{
		idx = 0;
		env = malloc(sizeof(env_t));
		env->name = str_copy1(envp[i], &idx, '=');
		idx++;
		env->value = str_copy1(envp[i], &idx, 0);
		env->next = NULL;
		lstadd_back_env(&head, env);
		i++;
	}
	global->env = head;
	global->commands = NULL;
	global->exit_code = 0;
	global->pid = getpid();
	global->alias = NULL;
	global->envp = envp;
	global->n = 1;
}

/**
 * env_search - Searches for an env var by name
 * @str: The name of the env var to search for
 * @gloabal: A pointer to the global state struct
 * Return: The value of the env var if found, NULL if not found
 */
char *env_search(char *str, global_t *global)
{
	env_t *ptr;

	ptr = global->env;
	while (ptr)
	{
		if (ptr->name && !_strcmp(str, ptr->name, _strlen(str) + 1))
			return (ptr->value);
		ptr = ptr->next;
	}
	return (0);
}

/**
 * envsearch - Searches for an env var by name and returns
 * @str: The name of the env var to search for
 * @global: A pointer to the global state struct
 * Return: A pointer to the env var node if found, NULL if not found
 */
env_t *envsearch(char *str, global_t *global)
{
	env_t *ptr;

	ptr = global->env;
	while (ptr)
	{
		if (ptr->name && !_strcmp(str, ptr->name, _strlen(str) + 1))
			return (ptr);
		ptr = ptr->next;
	}
	return (0);
}
