/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:58:44 by moulmado          #+#    #+#             */
/*   Updated: 2022/04/14 16:22:43 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	// input = ft_strdup("ls | ls > cat && ls");
	// parcer(input);
	input = readline(PROMPT);
	while (input)
	{
		if(input != NULL && input[0] !='\0')
			add_history(input);
		if (!strcmp(input, "exit"))
			exit(0);
		parser(input);
		free(input);
		input = readline(PROMPT);
	}
}