#include "ft_printf.h"


t_var	*convert_flags(t_var *ls)
{
	int  i;
	
	i = 0;

			while (ls->action[ls->i] == '-' && ls->i++)
				ls->cnv[0] = '-';
			while (ls->action[ls->i] == '+' && ls->i++)
				ls->cnv[1] = '+';

	printf("%d",i);
	return (ls);
}


intmax_t 	getnum(t_var  *ls)
{
	intmax_t	num;
	num = (int) va_arg(ls->arguments,int);
	return (num);
}



t_var		*display(t_var *ls)
{
	int a = getnum(ls);
	ft_putnbr_fd(a,1);
	return (ls);
}