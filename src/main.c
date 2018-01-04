/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 01:38:19 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/31 01:57:27 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

extern	char **environ;

int		main(int ac, char **av, char **env)
{
	t_hashmap	*msh_env;

	(void)ac;
	(void)av;
	msh_load_env(&msh_env, env);
	msh_loop(msh_env);
	return (EXIT_SUCCESS);
}
