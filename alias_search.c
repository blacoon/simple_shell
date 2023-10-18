#include "shell.h"

/**
 * alias_search - Searches for an alias in the global alias list
 * @str: The name of the alias to search for
 * @global: Pointer to the global env struct
 * Return: The value of the alias found, NULL otherwise
 */
char	*alias_search(char	*str, global_t *global)
{
	alias_t	*ptr;

	ptr = global->alias;
	while (ptr)
	{
		if (ptr->name && !_strncmp(str, ptr->name, _strlen(str) + 1))
			return (ptr->value);
		ptr = ptr->next;
	}
	return (0);
}
/**
 * aliasSearch - Searches for an alias in the global alias list
 * @str: The name of the alias to search for.
 * @global: POinter to the global env structure
 * Return: Pointer to the alias_t struct if found, NULL otherwise
 */
alias_t	*aliassearch(char	*str, global_t *global)
{
	alias_t	*ptr;

	ptr = global->alias;
	while (ptr)
	{
		if (ptr->name && !_strncmp(str, ptr->name, _strlen(str) + 1))
			return (ptr);
		ptr = ptr->next;
	}
	return (0);
}
