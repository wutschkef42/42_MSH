/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 01:38:24 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/31 02:00:04 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

char	*msh_read_line(void)
{
	int		bufsize;
	int		position;
	char	*buffer;
	int		c;


	bufsize = MSH_RL_BUFSIZE;
	position = 0;
	if(!(buffer = malloc(sizeof(char) * bufsize)))
	{
		ft_printf("msh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	
	while (1)
	{
		c = getchar();

		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
			buffer[position] = c;
		position++;
		
		if (position >= bufsize)
		{
			bufsize += MSH_RL_BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				ft_printf("msh: allocation error\n");
				exit (EXIT_FAILURE);
			}		
		}
	}
}
