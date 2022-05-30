/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 11:45:16 by moulmado          #+#    #+#             */
/*   Updated: 2022/05/22 11:54:15 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_start(char *arg)
{
	int	index;
	int	start;

	index = 0;
	if (arg[index] == '-')
	{
		index++;
		while (arg[index] == 'n' && arg[index])
			index++;
		if (arg[index] == ' ')
			start = index + 1;
	}
	return (start);
}

static void	execute_echo(char *arg, int index)
{
	char	*var;

	while (arg[index])
	{
		if ()
	}
}

void	echo_cmd(char *arg)
{
	int	start;
	int	n;
	int	index;

	index = 0;
	start = find_start(arg);
	if (start)
		n = 1;
	execute_echo(arg, start);
}