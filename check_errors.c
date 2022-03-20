/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:13:52 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/18 16:14:46 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	loop_4_quotes(char *input, int *double_q, int *single_q)
{
	int index;

	index = 0;
	while (input[index])
	{
		if (input[index] == '\"')
		{
			if (*double_q == 1)
				*double_q -= 1;
			else
				*double_q += 1;
		}
		if (input[index] == '\'')
		{
			if (*single_q == 1)
				*single_q -= 1;
			else
				*single_q += 1;
		}
		index++;
	}
}

int check_4_parentheses(char *input)
{
	int prentheses;
	int index;

	prentheses = 0;
	index = 0;
	while(input[index])
	{
		if(input[index] == '(')
		{
			prentheses++;
		}
		if(input[index] == ')')
		{
			if(prentheses == 0)
			{
				prentheses--;
				break ;
			}
			prentheses--;
		}
		index++;
	}
	if (prentheses > 0)
	{
		error_msg("expected this \")\" to match this \"(\"\n");
		return (1);
	}
	if (prentheses < 0)
	{
		error_msg("expected this \"(\" before this \")\"\n");
		return (1);
	}
	return (0);
}

int	check_4_quotes(char *input)
{
	int double_q;
	int single_q;

	double_q = 0;
	single_q = 0;
	loop_4_quotes(input, &double_q, &single_q);
	if (single_q || double_q)
	{
		if (single_q)
		{
			error_msg("expected this \"\'\" to match this \"\'\"\n");
			return (1);
		}
		if (double_q)
		{
			error_msg("expected this \'\"\' to match this \'\"\'\n");
			return (1);
		}
	}
	return (0);	
}

int	check_errors(char *input)
{
	if (check_4_quotes(input))
		return (1);
	if	(check_4_parentheses(input))
		return (1);
	return (0);
}