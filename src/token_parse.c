
#include "msh.h"

char	**expand_env_vars(char **args, t_hashmap *msh_env)
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