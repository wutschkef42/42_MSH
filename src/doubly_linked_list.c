/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 18:35:47 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/31 18:35:51 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "doubly_linked_list.h"

void		dll_insert_head(t_dll_node **head, t_dll_node *new)
{
	if (!head)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	(*head)->prev = new;
	new->next = *head;
	(*head) = new;
}

void		dll_insert_tail(t_dll_node **head, t_dll_node *new)
{
	t_dll_node	*last;

	if (!head)
		return ;
	if (!(*head))
	{
		*head = new;
		return ;
	}
	last = *head;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

t_dll_node	*dll_new_node(char *data)
{
	t_dll_node	*new;

	if (!(new = malloc(sizeof(t_dll_node))))
		return (NULL);
	if (!(new->data = malloc(sizeof(char) * ft_strlen(data))))
		return (NULL);
	ft_strcpy(new->data, data);
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void		dll_print_forward(t_dll_node *head)
{
	ft_printf("DLL Forward:\n");
	while (head)
	{
		ft_printf("%s\n", head->data);
		head = head->next;
	}
	ft_printf("\n");
}

void		dll_print_backward(t_dll_node *head)
{
	ft_printf("DLL Backward:\n");
	while (head->next)
		head = head->next;
	while (head)
	{
		ft_printf("%s\n", head->data);
		head = head->prev;
	}
	ft_printf("\n");
}
