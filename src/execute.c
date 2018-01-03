/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 01:38:04 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/31 02:03:41 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		msh_cd(char **args);
int		msh_echo(char **args);
//int		msh_setenv(const char *name, const char *value, int replace);
//int		msh_unsetenv(const char *name);
int		msh_env();
int		msh_help(char **args);
int		msh_exit(char **args);

char	*builtin_str[] =
{
	"cd",
	"echo",
//	"setenv",
//	"unsetenv",
//	"env",
	"help",
	"exit"
};

int		(*builtin_func[]) (char**) =
{
	&msh_cd,
	&msh_echo,
//	&msh_setenv,
//	&msh_unsetenv,
//	&msh_env,
	&msh_help,
	&msh_exit
};

int		msh_num_builtins()
{
	return (sizeof(builtin_str) / sizeof(char*));
}

int		msh_cd(char **args)
{
	if (args[1] == NULL)
		ft_printf("msh: expected argument to \"cd\"\n");
	else
	{
		if (chdir(args[1]) != 0)
			perror("msh");
	}
	return (1);
}

int		msh_echo(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] != '"')
				write(1, &(args[i][j]), 1);	
			j++;
		}
		if (args[i + 1])
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
	return (1);
}


int		msh_set_env(t_hashmap *msh_env, const char *key, const char *value, int replace)
{
	if (!replace && hm_lookup(msh_env, key))
		return (0);
	hm_insert(msh_env, key, value);
	return (0);
}


int		msh_unset_env(t_hashmap *msh_env, const char *key)
{
	hm_delete(msh_env, key);
	return (0);

}

int		msh_get_env(t_hashmap *msh_env)
{
	t_dll_node	*head;
	char		*key;
	char		*value;

	head = *(msh_env->keychain);
	while (head)
	{
		key = (char*)head->data;
		value = hm_lookup(msh_env, key);
		ft_printf("%s=%s\n", key, value);
		head = head->next;
	}	
	return (0);
}

int		msh_help(char **args)
{
	int	i;
	
	(void)args;
	ft_printf("Felix Wutschke's MSH\n");
	ft_printf("Type program name and arguments, and hit enter.\n");
	ft_printf("The following are built in\n");
	i = 0;
	while (i < msh_num_builtins())
	{
		ft_printf("	%s\n", builtin_str[i]);
		i++;
	}

	ft_printf("Use the man command for information on other programs.\n");
	return (1);
}


int		msh_exit(char **args)
{
	(void)args;
	return(0);
}

int		msh_execute(char **args)
{
	int	i;
	
	if (args[0] == NULL)
		return (1);

	i = 0;
	while (i < msh_num_builtins())
	{
		if (ft_strcmp(args[0], builtin_str[i]) == 0)
			return ((*builtin_func[i])(args));
		i++;
	}
	return (msh_launch(args));
}
