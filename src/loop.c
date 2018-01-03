/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 01:38:16 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/31 01:58:22 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void	msh_loop(void)
{
	char	*line;
	char	**args;
	int		status;

	status = 1;
	while (status)
	{
		printf("$ ");
		line = msh_read_line();
		args = msh_split_line(line);
		status = msh_execute(args);

		free(line);
		free(args);

	}
}
