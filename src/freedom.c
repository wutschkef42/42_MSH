

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