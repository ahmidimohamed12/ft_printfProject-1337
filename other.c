#include "ft_printf.h"
#include <unistd.h>

static t_var	*display_percent(t_var *tab)
{
	if (tab->cnv[3] == '0' && tab->precision <= 0 && !tab->cnv[0])
	{
		tab->precision = tab->width;
		tab->width = 0;
	}
	if (tab->cnv[0] != '-')
		print(tab, ' ', tab->width - 1, 1);
	if (tab->cnv[3] == '0')
		print(tab, '0', tab->precision - 1, 1);
	write(1, "%", 1);
	if (tab->cnv[0] == '-')
		print(tab, ' ', tab->width - 1, 1);
	tab->len++;
	return (tab);
}

t_var			*display_other(t_var *tab)
{
	if (tab->cpy[tab->i] == '%')
	{
		display_percent(tab);
		return (tab);
	}
	if (tab->cnv[3] == '0' && tab->precision <= 0 && !tab->cnv[0])
	{
		tab->precision = tab->width;
		tab->width = 0;
	}
	if (tab->cnv[0] != '-')
		print(tab, ' ', tab->cnv[0] - 1, 1);
	if (tab->cnv[3] == '0')
		print(tab, '0', tab->precision - 1, 1);
	write(1, &tab->cpy[tab->i], 1);
	if (tab->cnv[0] == '-')
		print(tab, ' ', tab->cnv[0] - 1, 1);
	tab->len++;
	return (tab);
}