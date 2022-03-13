/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:58:44 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/13 12:10:25 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	color(int c_nb)
{
	if (c_nb == red)
		write(1, "\033[0;31m", ft_strlen("\033[0;31m"));
	if (c_nb == blue)
		write(1, "\033[0;34m", ft_strlen("\033[0;34m"));
	if (c_nb == cyan)
		write(1, "\033[1;36m", ft_strlen("\033[0;36m"));
	if (c_nb == yellow)
		write(1, "\033[0;33m", ft_strlen("\033[0;33m"));
	if (c_nb == white)
		write(1, "\033[0;37m", ft_strlen("\033[0;37m"));
	if (c_nb == green)
		write(1, "\033[0;32m", ft_strlen("\033[0;32m"));
}

void	prompt(void)
{
	color(green);
	write(1, "➜", ft_strlen("➜"));
	color(cyan);
	write(1, "  minishell ", ft_strlen("  minishell "));
	color(yellow);
	write(1, "✗ ", ft_strlen("✗ "));
	color(white);
}

void	sighandler(int sig)
{
	if (sig == 2)
	{
		write(1, "\n", 1);
		pro();
	}
	if (sig == SIGQUIT)
		return ;
}

int	main(int ac, char **av , char **env)
{
	char	*input;

	if (!env[0])
		return (0);
	signal(2, sighandler);
	signal(SIGQUIT, sighandler);
	prompt();
	input = get_next_line(0);
	while (input)
	{
		if (!strcmp(input, "exit\n"))
			exit(0);
		prompt();
		input = get_next_line(0);
	}
}
