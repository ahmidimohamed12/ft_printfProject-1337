#include "ft_printf.h"


void	ft_putnstr(int n)
{
	int  i;

	 i = 0;
	 while (i < n)
	 {
		 ft_putchar_fd(' ',1);
		 i++;
	 }
}


intmax_t		getnum(t_var *ls)
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




t_var	*display_d(t_var *ls)
{
	if (ls->width > 0 || ls->specifierCurrent != 's' || ls->point == 1)
		ft_putnstr(ls->width);
	if (ls->)
	

	return (ls);
}


t_var	*display(t_var *ls)
{
	//intmax_t a = getnum(ls);
	// if (ls->width > 0 && ls->specifierCurrent != 's')
	// 	ft_putnstr(ls->width);
	// if (ls->stars == '*')
	// 	ft_putnstr((int) a);
	// ls->stars = '\0';
	// ls->width = 0;
	if (ls->specifierCurrent == 'd' || ls->specifierCurrent == 'i' || ls->isstars == 1)
		display_d(ls);
	//if (ls->specifierCurrent == 'c')
		//ft_putchar_fd(get_char(ls) ,1);
	//if (ls->specifierCurrent == 's')
		//ft_putstr_fd(get_string(ls),1);
	return (ls);
}