/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 20:03:13 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/04 20:04:27 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

#define NUM_BUILTINS 7

int		msh_help(char **args)
{
	static char builtins[][9] = {"cd", "echo", "env", "setenv",
									"unsetenv", "exit", "help"};
	int			i;

	(void)args;
	ft_printf("\n*******************************************************");
	ft_printf("\n\t\tEcole 42 MSH - Minishell\n");
	ft_printf("*******************************************************\n");
	ft_printf("Type program name and arguments, and hit enter.\n");
	ft_printf("The following are built in\n");
	i = 0;
	while (i < NUM_BUILTINS)
	{
		ft_printf("\t%s\n", builtins[i]);
		i++;
	}
	ft_printf("Use the man command for information on other programs.\n\n");
	return (1);
}
