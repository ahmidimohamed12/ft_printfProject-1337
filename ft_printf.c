#include "ft_printf.h"

void    parse()
{

}

void ft_printf(const char *c,...)
{
    t_list *list;
    va_list ap;
    int i;
    va_start(ap, c); 
    list->format = c;
    i = va_arg(ap,int);
    ft_putnbr_fd(i,1); 
    va_end(ap);
    putchar('\n');
}

int main()
{
    int a = 20;
    ft_printf("%d",a);
    return (0);
}