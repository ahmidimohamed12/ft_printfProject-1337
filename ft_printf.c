#include "ft_printf.h"
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>

int	check(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned int)s1[i] - (unsigned int)s2[i] );
}

t_list	*speci(t_list *ls)
{
	while (ls->cpy[ls->i] != '\0')
	{
		if (ls->cpy[ls->i] == ls->specifier[ls->i])
			printf("%s",ls->cpy);

	}
	return (ls);
}


int	treat(t_list *ls)
{
	ls->i++;
	printf ("nomber i treat %d\n",ls->i);\
	ls  = convert_flags(ls);
	speci(ls);
	return (ls->len);
}


int	convert(t_list *ls)
{
	if (check(ls->cpy,"%") == 0)
		return (0);
	while (ls->cpy[ls->i] != '\0')
    	{
		if (ls->cpy[ls->i] == '%')
		{
			//end();	
			treat(ls);
		}
		else
		{
			write(1,&ls->cpy[ls->i],1);
			ls->len++;
		}
    		ls->i++;
	}
	printf("%d",ls->len);
	return (ls->len);
}

int ft_printf(const char *c,...)
{
	t_list *ls;
	if(!(ls =(t_list *) malloc(sizeof(t_list))))
		return (-1);
	ls->format = c;
	ls = init(ls);
	if (c)
	{
		va_start(ls->arguments,c);
		ls->len = convert(ls);
		va_end(ls->arguments);
	}
	return (ls->len);
}

int main()
{
	int r = 3;
	int a = ft_printf("ahmidi%dmohamed\n");
	return (0);
}
