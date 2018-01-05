/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 01:38:11 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/31 01:46:54 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		msh_launch(char **args, t_hashmap *msh_env)
{
	pid_t	pid;
	char	**env_serial;
	char	**paths;
	char	*link_executable;

	pid = fork();
	if (pid == 0)
	{
		if (!(paths = split_path(msh_env)))
		{
			ft_printf("msh: PATH is empty. Set: 'setenv PATH [path_1:..:path_n]'\n");
			return (0);
		}
		if (!(link_executable = seek_executable(paths, args[0])))
		{
			ft_printf("msh: command not found: %s\n", args[0]);
			return (0);
		}
		env_serial = hm_serialize(msh_env);
		if (execve(link_executable, args, env_serial) == -1)
			ft_printf("msh: error loading executable\n");
		exit (EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("msh");
	wait(&pid);
	return (1);
}
