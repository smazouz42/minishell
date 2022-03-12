/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:58:44 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/12 15:51:48 by smazouz          ###   ########.fr       */
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
		write(1, "\033[0;36m", ft_strlen("\033[0;36m"));
	if (c_nb == yellow)
		write(1, "\033[0;33m", ft_strlen("\033[0;33m"));
	if (c_nb == white)
		write(1, "\033[0;37m", ft_strlen("\033[0;37m"));
}

void	prompt(void)
{
	color(cyan);
	write(1, "➜  minishell ", ft_strlen("➜  minishell "));
	color(yellow);
	write(1, "✗ ", ft_strlen("✗ "));
	color(white);
}

int	main(int ac, char **av , char **env)
{
	char	*input;

	if (!env[0])
		return (0);
	prompt();
	input = get_next_line(0);
	while (input)
	{
		prompt();
		input = get_next_line(0);
	}
}
