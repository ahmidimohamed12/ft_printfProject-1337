#include "ft_printf.h"
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>


int		getnum(t_var *ls)
{
	intmax_t	num;
	if (ls->specifierCurrent == 'd' || ls->specifierCurrent == 'i')
		num  = (int) va_arg(ls->arguments,int);		
	return (num);
}

char	get_char(t_var *ls)
{
	int	car;
	if (ls->specifierCurrent == 'c')
		car  =  va_arg(ls->arguments,int);
	return (car);
}

char	*get_string(t_var *ls)
{
	char	*chaine;
	if (ls->specifierCurrent == 's')
		chaine = (char *) va_arg(ls->arguments,char *);
	
	return (chaine);
}

t_var	*display(t_var *ls)
{
	int a = getnum(ls);
	if (ls->specifierCurrent == 'd' || ls->specifierCurrent == 'i')
		ft_putnbr_fd(a,1);
	if (ls->specifierCurrent == 'c')
		ft_putchar_fd(get_char(ls) ,1);
	if (ls->specifierCurrent == 's')
		ft_putstr_fd(get_string(ls),1);
	return (ls);
}

t_var	*speci(t_var *ls)
{
	int	i;
	if (ls->nbflags == 1)
		ls->i++;
	i = 0;
	while (ls->specifier[i] != '\0')
	{
		if (ls->cpy[ls->i] == ls->specifier[i])
			ls->specifierCurrent = ls->specifier[i];
		i++;	
	}
	//printf("\n this specifier\n:%c",ls->specifierCurrent);
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






int	convert(t_var *ls)
{
	if (ft_strcmp((char *)ls->cpy,"%") == 0)
		return (0);
	while (ls->cpy[ls->i] != '\0')
    	{
		if (ls->cpy[ls->i] == '%')
		{

			ls->i++;
			testflag(ls);
			speci(ls);
			display(ls);
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
	int r = ft_printf("ahmidi%xmoha%dmed",-);

	return (0);
}
