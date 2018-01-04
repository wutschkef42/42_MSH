
#include "msh.h"

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
