#include "ft_printf.h"
#include <limits.h>

static intmax_t	get_num(t_var *tab)
{
	intmax_t	num;
	num = (int)(va_arg(tab->arguments, int));
	num = (intmax_t)num;
	return (num);
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




<<<<<<< HEAD
=======
	num = get_num(tab);
	if (num == 0 && tab->precision == 0)
	{
		if (tab->cnv[1] == '+s')
			display_wchar('+', tab);
		if (tab->cnv[2] == ' ')
			display_wchar(' ', tab);
		display_gap(tab, ' ', tab->field_width, 1);
		return (tab);
	}
	num_width = get_tens(num);
	align_left = (tab->convert[0] == '-') ? 1 : 0;
	if (tab->convert[3] == '0' && tab->precision == -1 && !tab->convert[0])
	{
		tab->precision = tab->field_width;
		if (num < 0 || tab->convert[2] || tab->convert[1] || tab->convert[0])
			tab->precision--;
	}
	do_d(tab, num, num_width, align_left);
	return (tab);
}
>>>>>>> 81b759f6f55ff2af69adaaa540a8dcaad99d4ae0
