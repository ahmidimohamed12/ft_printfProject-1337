# ifndef __FT_PRINTF__H
# define __FT_PRINTF__H

#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <sys/uio.h>
#include "mahmidi4/libft.h"

typedef struct s_var
{
    const char  *format;
    int        width;
    char        *specifier;// les chaine de formatage
    char        *prec;//presision 
    char        *flags;//flags -0.*
    int         len;
    char         *nbwidth;
    char	specifierCurrent; 
    int     point;
    int         i;
    char    stars;
    int     isstars;
    int     nbflags;
    va_list     arguments;
    char        *cpy;
    char	cnv[4];
    char	*action;
}               t_var;

int	            ft_strcmp(const char *s1,const char *s2);
void            ft_putchar(char c);
void            ft_putnbr(int c);
void            ft_putnbr_fd(int c,int fd);
void            ft_putstr(char *s);
t_var           *init(t_var *list);
t_var 	        *convert_flags(t_var *ls);
t_var           *display(t_var *ls);
t_var           *end(t_var *ls);
int             convert(t_var *list);
#endif