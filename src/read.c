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
#include "get_next_line.h"

char	*msh_read_line(void)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line))
		return (line);
	return (NULL);
}
