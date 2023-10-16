#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

/**
 * struct command_s - singly linked list
 * @path: the path.
 * @args: the args.
 * @tmp: the tmp.
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for command.
 */
typedef struct command_s
{
	char *path;
	char **args;
	char *tmp;
	struct command_s *next;
} command_t;

/**
 * struct alias_s - singly linked list
 * @name: the nmae.
 * @value: the value.
 * @next: points to the next node.
 *
 * Description: singly linked list node structure
 * for alias.
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

/**
 * struct env_s - singly linked list
 * @name: the name.
 * @value: the value.
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for env.
 */
typedef struct env_s
{
	char *name;
	char *value;
	struct env_s *next;
} env_t;

/**
 * struct global_s - global variable.
 * @commands: the commands.
 * @env: the env.
 * @alias: the alias.
 * @exit_code: the exit code.
 * @pid: the pid.
 * @name: the name.
 * @envp: the envp.
 * @cmd: the cmd.
 * @left: the left.
 * @n: the line num.
 * @fd: the fd.
 *
 * Description: global variable.
 */
typedef struct global_s
{
	command_t *commands;
	env_t *env;
	alias_t *alias;
	int exit_code;
	pid_t pid;
	char *name;
	char **envp;
	char *cmd;
	char *left;
	int n;
	int fd;
} global_t;

# define BUFFER_SIZE 1024

/**
 * Function Prototypes
 */
char *var_re(char *ptr, global_t *global);
size_t _strlen(const char *s);
char *_strdup(const char *s1);
int _strcmp(const char *str1, const char *str2, size_t n);
void putnbr_fd(int n, int fd);
char *_itoa(int n);
int _atoi(char *s);
char *_strjoin(char *s1, char *s2);
void my_exit(char **cmd, global_t *global);
int is_num(char *str);
void handler(int sig);
int main(int ac, char **av, char **env);
char *_strjoin(char *s1, char *s2);
static char **m_error(char **arr);
static int ft_count_words(char const *str, char charset);
static int ft_word_len(char const *str, char charset);
static char *ft_word_grep(char const *str, char charset);
char **split(char const *s, char c);
void _alias(char **cmd, global_t *global);
char *alias_search(char *str, global_t *global);
alias_t *aliasSearch(char *str, global_t *global);
char *alias(char *ptr, global_t *global);



#endif
