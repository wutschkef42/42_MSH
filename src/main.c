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

extern	char **environ;

int		main(int ac, char **av)
{

	//t_dll_node	*dll;
	t_hashmap	*msh_env;

	(void)ac;
	(void)av;

	msh_load_env(&msh_env);
//	msh_set_env(msh_env, "FELIX", "AWESOME", 1);
//	msh_set_env(msh_env, "FELIX", "YEAH", 0);
//	msh_set_env(msh_env, "MIKE", "OK", 0);
//	msh_set_env(msh_env, "PHILIPPE", "GREAT", 1);
//	msh_unset_env(msh_env, "FELIX");
//	msh_unset_env(msh_env, "MIKE");
//	msh_unset_env(msh_env, "PHILIPPE");
//	msh_get_env(msh_env);
	msh_get_env(msh_env);
	msh_loop();

	/*
	int count = 0;
	while (environ[count])
	{
		ft_printf(">>>>%s\n", environ[count]);
		count++;
	}

	
	msh_env = hm_new_map(512);
	hm_insert(msh_env, "hello", "world");
	hm_insert(msh_env, "such", "wow");
	hm_insert(msh_env, "much", "good");
	hm_insert(msh_env, "very", "sleek");

	t_dll_node	*head;

	head = *(msh_env->keychain);
	while (head)
	{
		ft_printf("key: %s, value: %s\n", (char*)head->data,
			hm_lookup(msh_env, (char*)head->data));
		head = head->next;
	}

*/
/*
	dll = NULL;
	char	*str1 = malloc(20);
	char	*str2 = malloc(20);
	char	*str3 = malloc(20);

	ft_strcpy(str1, "hello felix");
	ft_strcpy(str2, "hello paul");
	ft_strcpy(str3, "hello micka");

	dll_insert_head(&dll, dll_new_node((void*)str1, ft_strlen(str1)));
	dll_insert_head(&dll, dll_new_node((void*)str2, ft_strlen(str2)));
	dll_insert_tail(&dll, dll_new_node((void*)str3, ft_strlen(str3)));

	dll_print_forward(dll);
	dll_delete_head(&dll);
	dll_delete_list(&dll);
	
	dll_insert_head(&dll, dll_new_node((void*)str1, ft_strlen(str1)));
	dll_insert_head(&dll, dll_new_node((void*)str2, ft_strlen(str2)));
	dll_insert_tail(&dll, dll_new_node((void*)str3, ft_strlen(str3)));
	dll_insert_head(&dll, dll_new_node((void*)str1, ft_strlen(str1)));
	dll_insert_head(&dll, dll_new_node((void*)str2, ft_strlen(str2)));
	dll_insert_tail(&dll, dll_new_node((void*)str3, ft_strlen(str3)));
	dll_insert_head(&dll, dll_new_node((void*)str1, ft_strlen(str1)));
	dll_insert_head(&dll, dll_new_node((void*)str2, ft_strlen(str2)));
	dll_insert_tail(&dll, dll_new_node((void*)str3, ft_strlen(str3)));
	dll_delete_node(&dll, (void*)"hello felix", 11, &ft_memcmp);


	//dll_delete_head(&dll);
	dll_print_backward(dll);

	//msh_load_env(&msh_env);

	
	
*/
	return (EXIT_SUCCESS);
}
