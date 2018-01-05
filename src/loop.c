/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 01:38:16 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/04 20:27:57 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "get_next_line.h"

void	msh_loop(t_hashmap *msh_env)
{
	char	*line;
	char	**args;
	int		status;

	status = 1;
	while (status)
	{
		ft_printf("$> ");
		line = msh_read_line();
		args = msh_tokenize(line, MSH_TOK_DELIM);
		args = token_preprocess(args, msh_env);
		status = msh_execute(args, msh_env);
		free(line);
		free(args);
	}
}
