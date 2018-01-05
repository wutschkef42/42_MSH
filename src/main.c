/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 01:38:19 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/04 20:27:09 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		main(int ac, char **av, char **env)
{
	t_hashmap	*msh_env;

	(void)ac;
	(void)av;
	msh_load_env(&msh_env, env);
	msh_loop(msh_env);
	return (EXIT_SUCCESS);
}
