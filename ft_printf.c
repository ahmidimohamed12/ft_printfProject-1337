#include "ft_printf.h"
#include <unistd.h>
#include<stdio.h>
#include <stddef.h>

void    ft_putchar(char c)
{
    write(1,&c,1);
}

void ft_putstr(char *s)
{
    int i;
    i = 0;
    while (s[i] != '\0')
    {
        ft_putchar(s[i]);
        i++;
    }
}

size_t ft_strlen(char *c)
{
    int i;
    while (c[i] != '\0')
        i++;
    return (i); 
}


int    parse(char s)
{
    int  i=0;
    if(s == 'd')
    {
        ft_putchar(s);
        i = 0;
    }
    else
        i = 1;
    return (i);
}

void    flag(char *f)
{
    int i;

    i = 0;
    int r;

    r = 0;
    while (f[i] != '\0')
    {   
        if(f[i] == '%')
        {
           r =  parse(f[i + 1]);
        }else
        {
            ft_putchar(f[i]);
        }
        i++;
    }
    if (r == 0)
        ft_putstr(f);
}

int count_porc(char *s)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '%')
            j++;
        i++;
    }
    return (j);
}

int ft_printf(char *c,...)
{
    int i;

    flag(c);
    return (ft_strlen(c));
}



int main()
{
//   int a =   ft_printf("ahmidi\n");
//     printf("%d",a);
int a = count_porc("hajjsd%kdd%s");
printf("%d",a);
    return (0);
}