# ifndef __FT_PRINTF__H
# define __FT_PRINTF__H

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <sys/uio.h>

typedef struct s_list
{
    const char  *format;
    int         width;//width 
    char        *specifier;// les chaine de formatage
    char        *prec;//presision 
    char        *flags;//flags +- #0
    int         len;
    char	specifierCurrent; 
    int         i;
    va_list     arguments;
    char        *cpy;
    char	cnv[5];
    char	*action;
}   t_list;


int	ft_strcmp(const char *s1,const char *s2);
void    ft_putchar(char c);
void    ft_putnbr(int c);
void    ft_putnbr_fd(int c,int fd);
void    ft_putstr(char *s);
t_list  *init(t_list *list);
t_list 	*convert_flags(t_list *ls);
int     convert(t_list *list);
//int	val(t_list *l);
#endif
