#include "ft_printf.h"
#include <stdarg.h>
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


int count(t_list *ls)
{
    while (ls->cpy != '\0')
    {
        ft_putchar(ls->cpy[ls->i]);
        if ( ls->cpy[ls->i] == 'd' && ls->cpy[ls->i] == 'D')
            ls->len++;
        ls->i++;
    }
    //ft_putstr(ls->cpy);
    return (ls->len);
}

int ft_printf(const char *c,...)
{
    t_list *list;
    va_list  ls;
    int r;
    list->format = c;
    va_start(ls,c);
    printf("%d",count(list));
    va_end(ls);
    return (0);
}

int main()
{
    int a;
    t_list *ls;
    ls->format = "ahmidi";
    start(ls);
    a = count(ls);
    printf("%d",a);
    return (0);
}