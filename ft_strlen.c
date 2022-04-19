#include"minishell.h"

size_t ft_strlen(const char *str)
{
    size_t index = 0;

    if(!str)
        return(0);
    while(str[index])
        index++;
    return(index);
}