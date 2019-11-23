# ifndef __FT_PRINTF__H
# define __FT_PRINTF__H

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <ctype.h>


typedef struct s_list
{
    const char  *format;
    int         width;//width 
    char        *specifier;// les chaine de formatage
    char        *prec;//presision 
    char        *flags;//flags +- #0
    int         len; 
    int         i;
    va_list     args;
    char        *cpy;
    int id;
}   t_list;


void    ft_putchar(char c);
void    ft_putnbr(int c);
void    ft_putnbr_fd(int c,int fd);
void    ft_putstr(char *s);
t_list  start(t_list list);
#endif