/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_parentheses.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:16:52 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/17 17:08:44 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_add_size(char *input)
{
	int index;
	int	add_size;

	add_size = 1;
	index = 0;
	while (input[index])
	{
		if ((input[index] == '&' && input[index + 1] == '&')
			|| (input[index] == '|' && input[index + 1] == '|'))
			add_size += 2;
		index++;
	}
	return (add_size++, add_size);
}

// char	*add_prnths_util(char *re, char *input)
// {
	
// }

char	*add_parentheses(char *input)
{
	char	*re;
	int		index;
	int		input_i;

	re = (char *)malloc(slen(input) + count_add_size(input) + 1);
	re[0] = '(';
	index = 1;
	input_i = 0;
	while (index < slen(input) + count_add_size(input) - 1)
	{
		if ((input[input_i] == '&' && input[input_i + 1] == '&')
			|| (input[input_i] == '|' && input[input_i + 1] == '|'))
		{
			re[index++] = ')';
			re[index++] = input[input_i++];
		}
		else if (((input[input_i - 2] == '&' && input[input_i - 1] == '&')
			|| (input[input_i - 2] == '|' && input[input_i - 1] == '|'))
			&& re[index - 1] != '(')
			re[index++] = '(';
		else
			re[index++] = input[input_i++];
	}
	return(re[index++] = ')',re[index] = '\0', re);
}