#include "ft_printf.h"

t_list  *init(t_list *list)
{
    list->len = 0;
    list->flags = "+- #0";
    list->specifier = "ds";
    list->i = 0;
    list->cpy = (char *)list->format;
    list->action = (char *) list->format;
    return (list);
}
