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




