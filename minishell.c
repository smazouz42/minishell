/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:58:44 by moulmado          #+#    #+#             */
/*   Updated: 2022/04/19 22:47:25 by smazouz          ###   ########.fr       */
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
int	ft_size_count(char **env)
{
	int	size;

	size = 0;
	while (env[size])
		size++;
	return (size);
}
char **envdup(char **env)
{
	char **new_env;
	int index;
	if(!env)
		exit(1);
	index = 0;
	new_env = (char **)malloc((ft_size_count(env) + 1) * sizeof(char *));
	// if(!new_env)
	// 	exit(10);
	while(env[index])
	{
		new_env[index] = env[index];
		index++;
	}
	new_env[index] = NULL;
	return(new_env);
}
int	main(int ac, char **av, char **env)
{
	char	*input;
	t_tree *tree;

	(void)ac;
	(void)av;
	(void)env;
	char **new_env;
	if (!env[0])
		return (0);

	signal(2, sighandler);
	signal(SIGQUIT, sighandler);
	// input = ft_strdup("ls | ls > cat && ls");
	// parcer(input);
	input = readline(PROMPT);
	// input = "ls > lol";
	while (input)
	{
		if(input != NULL && input[0] !='\0')
			add_history(input);
		if (!strcmp(input, "exit"))
			exit(0);
		tree = parser(input, env);
		new_env = envdup(env);
		ft_execution(tree, new_env , 1 , 0);
		free(input);
		input = readline(PROMPT);
	}
}