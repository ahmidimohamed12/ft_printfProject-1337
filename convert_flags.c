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