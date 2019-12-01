#include "ft_printf.h"

t_var   *init(t_var *list)
{
    list->len = 0;
    list->flags = "-0.*";
    list->specifier = "cspdiuxX%";
    list->nbflags = 0;
    list->point = 0;
    list->i = 0;
    list->cpy = (char *)list->format;
    list->action = (char *) list->format;
    return (list);
}

t_var   *end(t_var *ls)
{ 
    ls->cnv[0] = '\0';
    ls->cnv[1] = '\0';
    ls->cnv[2] = '\0';
    ls->cnv[3] = '\0';
    return (ls);
}
