#include "ft_printf.h"

t_list  *start(t_list *list)
{
    list->len = 0;
    list->flags = "+- #0";
    list->specifier = "ds";
    list->i = 0;
    list->cpy = (char *)list->format;
    return (list);
}