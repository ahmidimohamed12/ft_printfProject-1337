#include "libft.h"
#include <stdio.h>

int	ft_strcmp(const char *s1,const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned int) s1[i] - (unsigned int)s2[i]);
}

int main()
{
	
	printf ("%d",ft_strcmp("ahmidi","ahmidi"));
	
}
