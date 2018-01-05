/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 20:04:54 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/04 20:05:03 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

char	*expand_tilde(t_hashmap *msh_env, char *path)
{
	char	*full_path;

	full_path = ft_strdup(hm_lookup(msh_env, "HOME"));
	full_path = ft_strjoin(full_path, "/");
	full_path = ft_strjoin(full_path, path + 1);
	return (full_path);
}

int		msh_cd(char **args, t_hashmap *msh_env)
{
	char	*pwd;
	char	*full_path;

	if (!(pwd = malloc(sizeof(char) * MSH_PWD_BUFSIZE)))
	{
		ft_printf("msh: memory allocation error\n");
		return (0);
	}
	else if (!args[1])
	{
		if (chdir(hm_lookup(msh_env, "HOME")))
			ft_printf("msh: HOME not set. I don't know where to go.\n");
		return (1);
	}
	else if (ft_strcmp(args[1], "-") == 0)
	{
		if (chdir(hm_lookup(msh_env, "PWD_OLD")))
			chdir(hm_lookup(msh_env, "HOME"));
	}
	else if (args[1][0] == '~')
	{
		full_path = expand_tilde(msh_env, args[1]);
		if (chdir(full_path))
			ft_printf("msh: Error interpreting ~\n");
		free(full_path);
	}
	else
	{
		if (chdir(args[1]) != 0)
			ft_printf("msh: Directory doesn't exist or you lack permissions.\n");
	}
	hm_insert(msh_env, "PWD_OLD", hm_lookup(msh_env, "PWD"));
	hm_insert(msh_env, "PWD", getcwd(pwd, MSH_PWD_BUFSIZE));
	free(pwd);
	return (1);
}
