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

# include <sys/wait.h>		// waitpid() and associated macros
# include <unistd.h>		// chdir(), fork(), exec(), pid_t, char **environ
# include <stdlib.h>		// malloc(), realloc(), free(), exit(), execvp(), EXIT_SUCCESS, EXIT_FAILURE
# include <stdio.h>			// stderr, getcher(), perror()
# include <string.h>		// strtok()
		
void	msh_loop(void);						// LOOOP
char	*msh_read_line(void);				// READ
char	**msh_split_line(char *line);		// PARSE
int		msh_launch(char **args);			// INIT
int		msh_execute(char **args);			// EVAL

int		msh_num_builtins();					// BUILT-INS
int		msh_cd(char **av);
int		msh_help(char **av);
int		msh_exit(char **av);

int		msh_load_env(t_hashmap **msh_env);	

char	*ft_strndup(const char *s, size_t n);

#endif
