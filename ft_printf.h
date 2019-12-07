# ifndef __FT_PRINTF__H
# define __FT_PRINTF__H

#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <ctype.h>
# include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <sys/uio.h>
#include "mahmidi4/mahmidi4/libft.h"

typedef struct s_var
{
    const char  *format;
    int         width;
    char        *specifier;// les chaine de formatage
    char        *prec;//presision 
    char        *flags;//flags -0.*
    int         len;
    char         *nbwidth;
    char	    specifierCurrent; 
    int         point;
    int         precision;
    int         i;
    int         nbflags;
    va_list     arguments;
    char        *cpy;
    char	    cnv[5];
    int         przero;
    char	    *action;
}               t_var;
int	            ft_strcmp(const char *s1,const char *s2);
void            ft_putchar(char c);
void            ft_putnbr(int c);
void            ft_putnbr_fd(int c,int fd);
void            ft_putstr(char *s);
t_var           *init(t_var *list);
t_var 	        *convert_flags(t_var *ls);
t_var	        *print(t_var *tab, intmax_t num, int num_width, int align_left);
t_var           *display(t_var *ls);
t_var			*display_other(t_var *tab);
t_var           *end(t_var *ls);
t_var           *speci(t_var *ls);
char            get_negatvity_placeholder(t_var *tab, int is_negative);
int             convert(t_var *list);
#endif