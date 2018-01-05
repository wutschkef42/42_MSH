/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 01:14:18 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/31 01:55:00 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MSH_H
# define MSH_H

# define MSH_RL_BUFSIZE 1024
# define MSH_ENV_BUFSIZE 1024
# define MSH_TOK_BUFSIZE 64
# define MSH_TOK_DELIM " \t\r\n\a"

# include "libft.h"
# include "hashmap.h"
# include "doubly_linked_list.h"

# include <sys/wait.h>		// waitpid() and associated macros
# include <unistd.h>		// chdir(), fork(), exec(), pid_t, char **environ
# include <stdlib.h>		// malloc(), realloc(), free(), exit(), execvp(), EXIT_SUCCESS, EXIT_FAILURE
# include <stdio.h>			// stderr, getcher(), perror()

void	msh_loop(t_hashmap *msh_env);					// LOOOP
char	*msh_read_line(void);							// READ
char	**msh_tokenize(char const *s, char *delims);	// PARSE
int		msh_launch(char **args, t_hashmap *msh_env);	// INIT
int		msh_execute(char **args, t_hashmap *msh_env);	// EVAL

char	*seek_executable(char **paths, char *name);
char	**split_path(t_hashmap *msh_env);
char	*is_path(char *name);
char	*strip_quotes(const char *s);
char	**token_preprocess(char **args, t_hashmap *msh_env);


int		msh_cd(char **av);
int		msh_help(char **av);
int		msh_echo(char **av);
int		msh_exit(char **av);

int		msh_load_env(t_hashmap **msh_env, char **env);
int		msh_get_env(t_hashmap *msh_env);
int		msh_set_env(t_hashmap *msh_env, const char *key, const char *value, int replace);
int		msh_unset_env(t_hashmap *hashmap, const char *key);
int		msh_set_env_usage();

char	*ft_strndup(const char *s, size_t n);


#endif
