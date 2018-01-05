/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 01:38:04 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/31 02:03:41 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		msh_execute(char **args, t_hashmap *msh_env)
{
	int	i;
	
	if (args[0] == NULL)
		return (1);

	i = 0;
	if (ft_strcmp(args[0], "echo") == 0)
		return (msh_echo(args));
	if (ft_strcmp(args[0], "setenv") == 0)
		return (args[1] && args[2] ? msh_set_env(msh_env, args[1], args[2], 1) : msh_set_env_usage());
	if (ft_strcmp(args[0], "unsetenv") == 0)
		return (msh_unset_env(msh_env, args[1]));
	if (ft_strcmp(args[0], "env") == 0)
		return (msh_get_env(msh_env));
	if (ft_strcmp(args[0], "cd") == 0)
		return (msh_cd(args, msh_env));
	if (ft_strcmp(args[0], "help") == 0)
		return (msh_help(args));
	if (ft_strcmp(args[0], "exit") == 0)
		return (msh_exit(args));

	return (msh_launch(args, msh_env));
}
