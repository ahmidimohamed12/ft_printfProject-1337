#include "ft_printf.h"
#include <ctype.h>

t_list  *display_int (t_list *l)
{
    int nu;
    nu = va_arg(l->args,int);
    return (l);
}

t_list  *display(t_list *l)
{
    char *f;
    f = l->flags;
    if (*f == 'd')
        display_int(l);
    return (l);
}


int treat(t_list *list)
{
    display(list);
    return (list->i);
}


int    convert(t_list   *list)
{
    if (list->cpy[list->i] != '\0')
    {
        if (list->cpy[list->i] == '%')
		{
			treat(list);
		}
		else
		{
			ft_putstr(list->cpy);
			list->len++;
		}
        list->i++;
    }
    return (list->i);
}

int ft_printf(const char *c,...)
{
    t_list *list;
   
   return (list->len);
}

int main()
{
    int a;
    int r =  ft_printf("kkjdjfjkdjf\n");
    a = printf("kkjdjfjkdjf\n");
    printf("%d",a);
    return (0);
}