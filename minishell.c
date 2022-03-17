/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:58:44 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/17 15:23:19 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	color(int c_nb)
{
	if (c_nb == red)
		write(1, "\033[0;31m", slen("\033[0;31m"));
	if (c_nb == blue)
		write(1, "\033[0;34m", slen("\033[0;34m"));
	if (c_nb == cyan)
		write(1, "\033[1;36m", slen("\033[0;36m"));
	if (c_nb == yellow)
		write(1, "\033[0;33m", slen("\033[0;33m"));
	if (c_nb == white)
		write(1, "\033[0;37m", slen("\033[0;37m"));
	if (c_nb == green)
		write(1, "\033[0;32m", slen("\033[0;32m"));
}

void	sighandler(int sig)
{
	if (sig == SIGINT)
	{
		write(1,"\n",1);
		rl_on_new_line();
		rl_replace_line("",0);
		rl_redisplay();
	}
	if (sig == SIGQUIT)
		return ;
}

int	main(int ac, char **av, char **env)
{
	char	*input;

	(void)ac;
	(void)av;
	(void)env;
	if (!env[0])
		return (0);

	signal(2, sighandler);
	signal(SIGQUIT, sighandler);
	input = readline(PROMPT);
	while (input)
	{
		if(input != NULL && input[0] !='\0')
			add_history(input);
		if (!strcmp(input, "exit"))
			exit(0);
		parcer(input);
		free(input);
		input = readline(PROMPT);
	}
}
