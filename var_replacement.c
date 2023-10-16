#include "shell.h"

/**
 * help_var_re - Replace variables in a string
 * @ptr: the input string
 * @global: pointer to global_t structure
 *
 * Return: Pointer to modified string
 */
char *help_var_re(char *ptr, global_t *global)
{
	int i = 0;
	char **str = split(ptr, ' '), *str2 = NULL, *tmp;

	while (str[i])
	{
		if (str[i][0] == '$' && str[i][1])
		{
			tmp = str[i];
			if (env_search(str[i] + 1, global))
				str[i] = _strdup(env_search(str[i] + 1, global));
			else
				str[i] = _strdup('');
			free(tmp);
		}
		i++;
	}

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	free(ptr);
	return (str2);
}

/**
 * var_re - Replace special variables in a string
 * @ptr: The input string
 * @global: Pointer to global_t structure
 *
 * Return: Pointer to the modified string
 */
char *var_re(char *ptr, global_t *global)
{
	char *str = NULL, *tmp;
	int i = 0, j = 0;

	if (!ptr)
		return (NULL);

	while (ptr[i])
	{
		if (!_strcmp(ptr + i, "$$", 2) || !_strcmp(ptr + i, "$?", 2))
		{
			if (!_strcmp(ptr + i, "$$", 2))
				tmp = _itoa(global->pid);
			else if (!_strcmp(ptr + i, "$?", 2))
				tmp = _itoa(global->exit_code);
			ptr[i] = 0;
			str = _strjoin(str, ptr + j);
			str = _strjoin(str, tmp);
			free(tmp);
			ptr[i] = '$';
			i++;
			j = i + 1;
		}
		if (ptr[i])
			i++;
	}

	if (!str)
		str = _strdup(ptr);
	free(ptr);
	return (help_var_re(str, global));
}
