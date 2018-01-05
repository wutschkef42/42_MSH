
#include "msh.h"

int		msh_set_env(t_hashmap *msh_env, const char *key, const char *value, int replace)
{
	if (!replace && hm_lookup(msh_env, key))
		return (0);
	if (*value == '"')
		value = strip_quotes(value);
	hm_insert(msh_env, key, value);
	return (1);
}


int		msh_unset_env(t_hashmap *msh_env, const char *key)
{
	hm_delete(msh_env, key);
	return (1);

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
	return (1);
}

int		msh_set_env_usage()
{
	ft_printf("setenv [NAME][VALUE]\n");
	return (1);
}
