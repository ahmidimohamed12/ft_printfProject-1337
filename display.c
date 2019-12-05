#include "ft_printf.h"
#include <stddef.h>
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
	{
		num  = (int) va_arg(ls->arguments,int);
	}
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

 char		get_negatvity_placeholder(t_var *tab, int is_negative)
{
	char	*tmp;

	tmp = tab->cnv;
	if (is_negative)
		return ('-');
	if (tmp[1] == '+')
		return ('+');
	if (tmp[2] == ' ')
		return (' ');
	return ('\0');
}

 void display_gap(t_var *ls, char c ,int len , int update)
{
	char *str;

	if (len > 0)
	{
		if (update)
			ls->len += len;
		if (!(str =(char *) malloc(len)))
			exit(-1);
		ft_memset(str,c,len);
		write(1,str,len);
	 	free(str);
	}
}


t_var	*print(t_var *tab, intmax_t num, int num_width, int align_left)
{
	int		notvide;
	char		negatvity_placeholder;
	int			is_negative;
	is_negative = (num < 0) ? 1 : 0;
	num *= (is_negative && num != (-9223372036854775807 - 1)) ? -1 : 1;
	negatvity_placeholder = get_negatvity_placeholder(tab, is_negative);
	notvide = num_width;
	if (num_width <= tab->precision && tab->precision >= 0)
	 	notvide = tab->precision;
	if (negatvity_placeholder)
		notvide++;
	 tab->len += (notvide <= tab->width) ? tab->width : notvide;
	 printf("\nlength%d\n",tab->len);
	//if (!align_left)
	//	display_gap(tab, ' ', tab->width - notvide, 0);
	if (negatvity_placeholder)
		write(1, &negatvity_placeholder, 1);
	//print(tab, '0', tab->precision - num_width, 0);
	if (num != (-9223372036854775807 - 1))
	{
		//ft_putnbrmax_fd(num, 1);
		ft_putnbr_fd(num,1);
	}
	else if ((tab->len += 18) > 0)
		write(1, "9223372036854775808", 19);
	//if (align_left)
	//	display_gap(tab, ' ', tab->width - notvide, 0);
	//ft_putnbr_fd(num,1);

	return (tab);
 }




t_var			*display_d(t_var *tab)
{
	intmax_t	num;
	int			num_width;
	int			align_left;
	char neg;
	char	*d;
	int p;

	p = 0;
	align_left = 0;
	num = getnum(tab);
	neg = get_negatvity_placeholder(tab,align_left);
	//num_width = get_tens(num);
	//printf ("\nnum width is ==>%d\n",num_width);
	align_left = (tab->cnv[0] == '-') ? 1 : 0;
	//printf("\nhhhh%d\n",align_left);
	p = (tab->cnv[2] == '0') ? 1 : 0;
	d = ft_itoa(num);
	neg = 	get_negatvity_placeholder(tab,align_left);
	//printf("\ndjdfd===>%d\n",neg);
	// if ( == '-')
	// {
	// 	//ft_putchar('-');
	// 	display_gap(tab,'-',tab->width ,align_left);
	// 	tab->cnv[0] = '\0';
	// }
	if (p == 1 || neg == '-')
	{
		display_gap(tab, '0', tab->width - 	ft_strlen(d), align_left);
		tab->width = 0;
	}
	if (tab->width > 0 && p == 0)
	{
		display_gap(tab, ' ', tab->width - ft_strlen(d), align_left);
		tab->width = 0;
	}
	
	print(tab, num, tab->width, align_left);
	return (tab);
}

t_var	*display_c(t_var *tab)
{
	ft_putchar(get_char(tab));
	return (tab);
}

t_var	*display_s(t_var *tab)
{
	ft_putstr_fd(get_string(tab),1);
	return (tab);
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
	//printf ("\n%d\n",ls->precision);
	if (ls->specifierCurrent == 'd' || ls->specifierCurrent == 'i' || ls->isstars == 1)
		display_d(ls);
	if (ls->specifierCurrent == 'c')
		display_c(ls);
	if (ls->specifierCurrent == 's')
		display_s(ls);
	//else
	//	display_other(ls);
	
	//if (ls->specifierCurrent == 'c')
		//ft_putchar_fd(get_char(ls) ,1);
	//if (ls->specifierCurrent == 's')
		//ft_putstr_fd(get_string(ls),1);
	return (ls);
}