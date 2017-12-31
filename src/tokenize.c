/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 01:37:42 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/31 01:41:59 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

char	**msh_split_line(char *line)
{
	int		bufsize;
	char	**tokens;
	char	*token;
	int		position;

	bufsize = MSH_TOK_BUFSIZE;
	if (!(tokens = malloc(sizeof(char*) * bufsize)))
	{
		ft_printf("msh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	position = 0;
	token = strtok(line, MSH_TOK_DELIM);
	while (token)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += MSH_TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens)
			{
				ft_printf("msh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		
		token = strtok(NULL, MSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}
