#include "ft_printf.h"
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>

int	check(const char *s1)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == '%')
			return (1);
		i++;
	}
	return (0);
}

int count(t_list *ls)
{
	if (check(ls->cpy) == 0)
		return (0);
	while (ls->cpy[ls->i] != '\0')
    	{
        	if (ls->cpy[ls->i] == 'd' || ls->cpy[ls->i] == 'i' )
            	{
			
			ls->len++;
		}
        	ls->i++;
    	}
	return (ls->len);
}

int ft_printf(const char *c,...)
{
	t_list *ls;
	int rr;
	va_list ap;
	if(!(ls =(t_list *) malloc(sizeof(t_list))))
		return (-1);
	ls->format = c;
	va_start(ap,c);
	if (ap)
	{
		init(ls);
		if ((rr = check(c)) == 0)
			ft_putstr((char *)c);
		else
			//start();
	}
	va_end(ap);
	return (rr);
}

int main()
{
	ft_printf("ah%midi");
	return (0);
}
