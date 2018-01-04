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
	pid_t	wpid;
	int		status;
	char	**env_serial;
	char	*link_executable;

	pid = fork();
	if (pid == 0)
	{
		if (!(link_executable = seek_executable(split_path(msh_env), args[0])))
		{
			ft_printf("cannot find executable\n");
			return (1);
		}
		// Child process
		env_serial = hm_serialize(msh_env);	
		if (execve(link_executable, args, env_serial) == -1)
			ft_printf("cannot find executable\n");
		exit (EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("msh");
	wpid = 1;
	status = 1;
	wait(&pid);
	//free(env_serial);
	/*else
	{
		ft_printf("parent process\n");
		status = 1;
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		}
	}
	*/
	return (1);
}
