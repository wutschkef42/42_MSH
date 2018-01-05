/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 20:12:24 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/04 20:12:29 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
	return (0);
}

void	dll_delete_head(t_dll_node **head)
{
	t_dll_node	*node;

	if (!head)
		return ;
	if (!(*head))
		return ;
	node = *head;
	*head = node->next;
	free(node->data);
	node->data = NULL;
	free(node);
	node->prev = NULL;
	node->next = NULL;
}

void	dll_delete_list(t_dll_node **head)
{
	if (!head || !(*head))
		return ;
	while (*head)
	{
		dll_delete_head(head);
		*head = (*head)->next;
	}
}
