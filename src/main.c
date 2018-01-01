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

int		main(int ac, char **av)
{
	t_hashmap	*msh_env;
	(void)ac;
	(void)av;

	msh_load_env(&msh_env);

	
	//msh_loop();
	return (EXIT_SUCCESS);
}
