/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 20:01:09 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/04 20:01:53 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		msh_echo(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] != '"')
				write(1, &(args[i][j]), 1);
			j++;
		}
		if (args[i + 1])
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
	return (1);
}
