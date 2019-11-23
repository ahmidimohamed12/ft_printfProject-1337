# ifndef __FT_PRINTF__H
# define __FT_PRINTF__H

#include <unistd.h>
#include <stdarg.h>

typedef struct s_list
{
    char    *args;
    int id;
    struct s_list *next;
}   t_list;



#endif