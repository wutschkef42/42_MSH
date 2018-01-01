
#include "msh.h"
#include "hashmap.h"

extern char	**environ;


/*
static int	string2hashmap(t_hashmap *hashmap, const char *envi)
{
	char	*key;
	char	*value;

	key = ft_strndup(envi, ft_strchr(envi, '=') - envi);
	value = ft_strdup(ft_strchr(envi, '=') + 1);
	hm_insert(hashmap, key, value);
	free(key);
	free(value);
	return (0);
}

int			msh_load_env(t_hashmap **msh_env)
{
	int			i;

	*msh_env = hm_new_map(MSH_ENV_BUFSIZE);
	i = 0;
	while (environ[i])
	{
		string2hashmap(*msh_env, environ[i]);
		i++;
	}
	return (0);
}
*/
