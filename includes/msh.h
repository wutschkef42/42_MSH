/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 01:14:18 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/04 21:05:18 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

# define MSH_RL_BUFSIZE 1024
# define MSH_ENV_BUFSIZE 1024
# define MSH_TOK_BUFSIZE 64
# define MSH_TOK_DELIM " \t\r\n\a"
# define MSH_PWD_BUFSIZE 1000

# include "libft.h"
# include "hashmap.h"
# include "doubly_linked_list.h"

# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	msh_loop(t_hashmap *msh_env);
char	*msh_read_line(void);
char	**msh_tokenize(char const *s, char *delims);
int		msh_launch(char **args, t_hashmap *msh_env);
int		msh_execute(char **args, t_hashmap *msh_env);

char	*seek_executable(char **paths, char *name);
char	**split_path(t_hashmap *msh_env);
char	*is_path(char *name);
char	*strip_quotes(const char *s);
char	**token_preprocess(char **args, t_hashmap *msh_env);

int		msh_cd(char **args, t_hashmap *msh_env);
int		msh_help(char **av);
int		msh_echo(char **av);
int		msh_exit(char **av);

int		msh_load_env(t_hashmap **msh_env, char **env);
int		msh_get_env(t_hashmap *msh_env);
int		msh_set_env(t_hashmap *msh_env, const char *key,
		const char *value, int replace);
int		msh_unset_env(t_hashmap *hashmap, const char *key);
int		msh_set_env_usage();

char	*ft_strndup(const char *s, size_t n);

#endif
