
#include "ft_printf.h"

t_var			*display_s(t_var *tab)
{
	char		*s;
	int			i;
	int			len;

	i = 0;
	s = va_arg(tab->arguments, char *);
	if (tab->precision > -1 && s)
		s = ft_strndup(s, tab->precision);
	else if (tab->precision == -1 && s)
		s = ft_strdup(s);
	else if (tab->precision > -1 && !s)
		s = ft_strndup("(null)", tab->precision);
	else if (tab->precision == -1 && !s)
		s = ft_strdup("(null)");
	len = ft_strlen(s);
	tab->len += len;
	if (tab->cnv[3] == '0' && tab->cnv[0] != '-')
		display_gap(tab, '0', tab->width - len, 1);
	else if (tab->cnv[0] != '-')
		display_gap(tab, ' ', tab->width - len, 1);
	ft_putstr(s);
	if (tab->cnv[0] == '-')
		display_gap(tab, ' ', tab->width - len, 1);
	free(s);
	return (tab);
}
