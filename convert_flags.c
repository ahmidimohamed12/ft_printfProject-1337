#include "ft_printf.h"


t_list	*convert_flags(t_list *ls)
{
	int  i;
	
	i = 0;

	while (ls->flags[i] != '\0')
	{
	/*
		while (ls->cpy[ls->i] == ls->action[ls->i])
		{
			while (ls->action[ls->i] == '-' && ls->i++)
				ls->cnv[0] = '-';
		}
	*/
		i++;
	}
	printf("this flags :%d\n",i);
	return (ls);
}


/*
t_list	*detect_specifier(t_list *ls)
{
	


}
*/
