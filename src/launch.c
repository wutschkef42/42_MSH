/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 01:38:11 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/04 20:25:27 by wutschkef        ###   ########.fr       */
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
		env_serial = hm_serialize(msh_env);
		if (!(paths = split_path(msh_env)))
			ft_printf("msh: PATH is empty.'\n");
		else if (!(link_executable = seek_executable(paths, args[0])))
			ft_printf("msh: command not found: %s\n", args[0]);
		else if (execve(link_executable, args, env_serial) == -1)
			ft_printf("msh: error loading executable\n");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("msh");
	wait(&pid);
	return (1);
}
