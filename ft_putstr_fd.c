#include"minishell.h"
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	x;

	x = 0;
	if (s)
	{
		while (s[x])
		{
			ft_putchar_fd(s[x], fd);
			x++;
		}
	}
}