/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postfix_expression.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 4DeR <4DeR@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:45:32 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/26 12:24:05 by 4DeR             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_prio(char *line ,int len, int yes)
{
	if (yes == 1 &&  (line[len] == '|' || line[len] == '>' || line[len] == '<'))
		return (2);
	if (yes == 2 &&  (line[len] == '|' || line[len] == '&'))
		return (1);
	if ((line[len] == '>' || line[len] == '<') && yes == 2)
		return (2);
	return (0);
}

static void	get_op_nd_cmd(char *line, t_stack *stack, int *len, int yes)
{
	static int	tmp;
	int			prio;

	prio = get_prio(line, *len, yes);
	line = ft_strjoin(line,ft_substr(line, tmp, (*len - tmp)));
	if (!ft_lstsize(stack))
		stack = ft_lstnew(ft_substr(line, *len, yes), prio);
	else
	{
		if(prio == 999)
		{
			while (ft_lstlast(stack)->prio != 998)
			{
				stack->postfix = ft_strjoin(stack->postfix, ft_lstlast(stack)->op);
				ft_lstdellast(ft_lstlast(stack));
			}
			ft_lstdellast(ft_lstlast(stack));
		}
		else if(ft_lstlast(stack)->prio < prio)
			ft_lstadd_back(&stack,ft_lstnew(ft_substr(line, *len, yes), prio));
		else
		{
			stack->postfix = ft_strjoin(stack->postfix, ft_lstlast(stack)->op);
		}
	}
	tmp = *len + yes;
	*len+=yes;
}

char *postfix_expression(char *line)
{
	int len;
	t_stack *stack;

	stack = NULL;
	len = 0;
	while(line[len])
	{
		if(line[len] == '|' && line[len + 1] == '|')
			get_op_nd_cmd(line, stack, &len, 2);
		else if (line[len] == '&' && line[len + 1]== '&')
			get_op_nd_cmd(line, stack, &len, 2);
		else if(line[len] == '|' && line[len + 1] != '|')
			get_op_nd_cmd(line, stack, &len, 1);
		else if(line[len] == '>' && line[len + 1] == '>')
			get_op_nd_cmd(line, stack, &len, 2);
		else if(line[len] == '<' && line[len + 1] == '<')
			get_op_nd_cmd(line, stack, &len, 2);
		else if(line[len] == '<' && line[len + 1] != '<')
			get_op_nd_cmd(line, stack, &len, 1);
		else if(line[len] == '>' && line[len + 1] != '>')
			get_op_nd_cmd(line, stack, &len, 1);
		else if(line[len] == '(')
			get_op_nd_cmd(line, stack, &len, 998);
		else if(line[len] == '(')
			get_op_nd_cmd(line, stack, &len, 999);
		else
			len++;
	}
	return (line);
}

