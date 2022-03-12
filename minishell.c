/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:58:44 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/12 15:34:52 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define KNRM  "\x1B[0m"

int	main(int ac, char **av , char **env)
{
	char	*input;

	if (!env[0])
		return (0);
	printf("%sred\n", KNRM);

	write(1, "➜  minishell ✗ ", ft_strlen("➜  minishell ✗ "));
	input = get_next_line(0);
	while (input)
	{
		write(1, "➜  minishell ✗ ", ft_strlen("➜  minishell ✗ "));
		input = get_next_line(0);
	}
}
