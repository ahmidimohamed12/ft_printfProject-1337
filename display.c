#include "ft_printf.h"
#include <stddef.h>

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

intmax_t	get_num(t_var *tab)
{
	intmax_t	num;
	num = (int) va_arg(tab->arguments,int);
	num = (intmax_t)num;
	return (num);
}
char		get_negatvity_placeholder(t_var *tab, int is_negative)
{
	char	*tmp;

	tmp = tab->cnv;
	if (is_negative)
		return ('-');
	return ('\0');
}
static int		get_tens(intmax_t num)
{
	int tens;

	if (num < 0)
		num *= -1;
	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}



 t_var	*print(t_var *tab, intmax_t num, int num_width, int align_left)
{
	int			not_blank;
	char		negatvity_placeholder;
	int			is_negative;

	is_negative = (num < 0) ? 1 : 0;
	num *= (is_negative && num != (-9223372036854775807 - 1)) ? -1 : 1;
	negatvity_placeholder = get_negatvity_placeholder(tab, is_negative);
	not_blank = num_width;
	//printf ("\n===>%d\n",num_width);
	if (num_width <= tab->precision && tab->precision >= 0)
		not_blank = tab->precision;
	if (negatvity_placeholder)
		not_blank++;
	tab->len += (not_blank <= tab->width) ? tab->width : not_blank;
	//if (!align_left)
	//	display_gap(tab, ' ', tab->width - not_blank, 0);
	if (negatvity_placeholder)
		write(1, &negatvity_placeholder, 1);
	display_gap(tab, '0', tab->precision , 0);
	if (num != (-9223372036854775807 - 1))
	{
		tab->width = 0;
		tab->cnv[0] = '\0';
		ft_putnbr_fd(num,1);
	//	printf("\nwidth==>%d\n",tab->width);
		
		//ft_putnbrmax_fd(num, 1);
		
	}
	else if ((tab->len += 18) > 0)
		write(1, "9223372036854775808", 19);
	if (align_left)
		display_gap(tab, ' ', tab->width - not_blank, 0);
	return (tab);
}



t_var			*display_d(t_var *tab)
{
	intmax_t	num;
	int			num_width;
	int c;
	int			align_left;
	int b;

	b = 0;
	num = get_num(tab);
	char *k = ft_itoa((int)num);
	
	if (num == 0 && tab->precision == 0)
	{
		display_gap(tab, ' ', tab->width, 1);
		return (tab);
	}
	num_width = get_tens(num);
	align_left = (tab->cnv[0] == '-') ? 1 : 0;

	// if (tab->cnv[3] == '0' && tab->cnv[0] != '-')
	// 	display_gap(tab, '0', tab->width - 1, 1);
	// else if (tab->cnv[0] != '-')
	// 	display_gap(tab, ' ', tab->width - 1, 1);
	// //display_wchar(c, tab);
	// if (tab->cnv[0] == '-')
	// 	display_gap(tab, ' ', tab->width - 1, 1);

	//printf("\n===%d===\n",tab->width);



	if (tab->cnv[3] == '*' && tab->cnv[1] == '.')
	{

		//if (tab->cnv[2] == '0' && tab->width)
		c = get_num(tab);
		k = ft_itoa((int) c);
		//printf("\n====%s====\n",k);
		display_gap(tab,'0',num - ft_strlen(k),align_left);
		print(tab,c,num_width,align_left);
		b = 1;
	}
	if (tab->cnv[2] == '0' && tab->precision == -1 && !tab->cnv[0])
	{
		tab->precision = tab->width;
		if (num < 0 || tab->cnv[2] || tab->cnv[1] || tab->cnv[0])
			tab->precision--;
	}
	if (tab->width > 0)
		display_gap(tab,' ',num - tab->width,align_left);
	if (b == 0)
		print(tab, num, num_width, align_left);
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
	if (ls->specifierCurrent == 'd' || ls->specifierCurrent == 'i')
		display_d(ls);

	//if (ls->specifierCurrent == 's')
	//	display_s(ls);
	//else
	//	display_other(ls);
	
	//if (ls->specifierCurrent == 'c')
		//ft_putchar_fd(get_char(ls) ,1);
	//if (ls->specifierCurrent == 's')
		//ft_putstr_fd(get_string(ls),1);
	return (ls);
}