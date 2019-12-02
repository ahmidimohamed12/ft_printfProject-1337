#include "ft_printf.h"
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>



t_var	*parse_precision(t_var *ls)
{
	while (ls->cpy[tab->i] == '.')
	{
		ls->i++;
		ls->precision = 0;
	}
	while (ls->cpy[ls->i] >= '0' && ls->cpy[ls->i] <= '9')
	{
		ls->precision *= 10;
		ls->precision += (ls->cpy[ls->i] - 48);
		ls->i++;
	}
	return (ls);
}

t_var	*test_width(t_var *ls)
{
	if (ls->cpy[ls->i] == '.')
	{
		ls->point = 1;
		ls->i++;
	}
	if (isdigit(ls->cpy[ls->i]))
	{
		ls->width = (ls->cpy[ls->i] - 48);
		ls->i++;
	}
	return (ls);
}

t_var	*test_arg(t_var *ls)
{
	if (ls->nbflags == 1)
	{
		ls->i++;
	}
	return (ls);
}

t_var		*parse_convert(t_var *ls)
{
	int		i;

	i = 0;
	while (ls->flags[i] != '\0')
	{
		while (ls->flags[i] == ls->action[ls->i])
		{
			while (ls->action[ls->i] == '-' && ls->i++)
				ls->cnv[0] = '-';
			while (ls->action[ls->i] == '.' && ls->i++)
				ls->cnv[1] = '.';
			while (ls->action[ls->i] == '0' && ls->i++)
				ls->cnv[2] = '0';
			while (ls->action[ls->i] == '#' && ls->i++)
				ls->cnv[3] = '*';
			i = 0;
		}
		//printf ("\n%c\n",ls->cnv[i]);
		i++;
	}
	return (ls);
}
t_var	*speci(t_var *ls)
{
	int	i;
	if (ls->nbflags == 1 && !(ls->width))
		ls->i++;
	i = 0;
	ls->nbflags = 0;
	while (ls->specifier[i] != '\0')
	{
		if (ls->cpy[ls->i] == ls->specifier[i])
			ls->specifierCurrent = ls->specifier[i];
		i++;	
	}	
	return (ls);
}

t_var	*testflag(t_var *ls)
{
	int i;

	i = 0;
	while (ls->flags[i] != '\0')
	{
		if (ls->cpy[ls->i] == ls->flags[i])
		{
			ls->cnv[i] = ls->flags[i];
			ls->nbflags = 1;
		}
		i++;
	}
	return (ls);
}

int		treat(t_var *ls)
{
	ls->i++;

	parse_convert (ls);
	test_width(ls);
	parse_precision(ls);
	speci(ls);
	display(ls);
	return (ls->len);
}


int		convert(t_var *ls)
{
	if (ft_strcmp((char *)ls->cpy,"%") == 0)
		return (0);
	while (ls->cpy[ls->i] != '\0')
    	{
			if (ls->cpy[ls->i] == '%')
			{
				//ls->i++;
				treat(ls);
			}
			else
			{
				write(1,&ls->cpy[ls->i],1);
				ls->len++;
			}
    		ls->i++;
		}
	return (ls->len);
}

int ft_printf(const char *c,...)
{
	t_var *ls;
	if(!(ls =(t_var *) malloc(sizeof(t_var))))
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
	int r = ft_printf("ahmidi%0.5dmohamed",5);
	return (0);
}