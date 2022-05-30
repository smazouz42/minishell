#include"minishell.h"
int	is_alpha_n(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == '_')
		return (0);
	else
		return (1);
}