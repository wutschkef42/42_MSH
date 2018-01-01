/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 01:38:19 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/31 01:57:27 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include "doubly_linked_list.h"

int		main(int ac, char **av)
{
	//t_list		*msh_env;
	t_dll_node	*dll;

	(void)ac;
	(void)av;

	dll = NULL;
	char	*str1 = malloc(20);
	char	*str2 = malloc(20);
	char	*str3 = malloc(20);

	ft_strcpy(str1, "hello felix");
	ft_strcpy(str2, "hello paul");
	ft_strcpy(str3, "hello micka");

	dll_insert_head(&dll, dll_new_node("hello"));
	dll_insert_head(&dll, dll_new_node(str2));
	dll_insert_tail(&dll, dll_new_node(str3));

	dll_print_forward(dll);
	dll_print_backward(dll);

	//msh_load_env(&msh_env);

	
	//msh_loop();
	return (EXIT_SUCCESS);
}
