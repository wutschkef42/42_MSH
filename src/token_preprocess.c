/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_preprocess.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 20:26:08 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/04 20:28:29 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static char	**expand_env_vars(char **args, t_hashmap *msh_env)
{
	int		i;

	i = 0;
	while (args[i])
	{
		if (args[i][0] == '$')
			args[i] = ft_strdup(hm_lookup(msh_env, &(args[i][1])));
		i++;
	}
	return (args);
}

char		*strip_quotes(const char *s)
{
	char	*no_quotes;

	if (!(no_quotes = malloc(sizeof(char) * ft_strlen(s) - 1)))
		return (NULL);
	s++;
	ft_strncpy(no_quotes, s, ft_strlen(s) - 1);
	return (no_quotes);
}

char		**token_preprocess(char **args, t_hashmap *msh_env)
{
	args = expand_env_vars(args, msh_env);
	return (args);
}
