/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postfix_expression.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:45:32 by moulmado          #+#    #+#             */
/*   Updated: 2022/04/21 09:28:10 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_prio(char *line ,int len, int yes)
{
	if (yes == 1 && line[len] == '|')
		return (2);
	if (yes == 1 &&  (line[len] == '>' || line[len] == '<'))
		return (3);
	if (yes == 2 &&  (line[len] == '|' || line[len] == '&'))
		return (0);
	if ((line[len] == '>' || line[len] == '<') && yes == 2)
		return (3);
	if (line[len] == '(')
		return (1);
	if (line[len] == ')')
		return (999);
	return(0);
}

static char	*last_command(char *line, t_stack **stack, t_int *ints)
{
	char	*str;

	str = NULL;
	str = ft_strjoin(str,ft_substr(line, ints->tmp, (ints->len - ints->tmp)));
	while (ft_lstlast(*stack))
	{
		str = ft_strjoin(str, ft_lstlast(*stack)->op);
		ft_lstdellast(stack);
	}
	return (str);
}

static char	*get_op_nd_cmd(char *line, t_stack **stack, t_int *ints, int yes)
{
	int			prio;
	char		*str;

	str = NULL;
	if (yes == EXODIA)
	{
		return (last_command(line, stack, ints));
	}
	prio = get_prio(line, ints->len, yes);
	str = ft_strjoin(str,ft_substr(line, ints->tmp, (ints->len - ints->tmp)));
	if (!ft_lstsize(*stack))
		*stack = ft_lstnew(ft_substr(line, ints->len, yes), prio);
	else
	{
		if(prio == 999)
		{
			while (ft_lstlast(*stack)->prio != 1)
			{
				str = ft_strjoin(str, ft_lstlast(*stack)->op);
				ft_lstdellast(stack);
			}
			ft_lstdellast(stack);
		}
		else if (ft_lstlast(*stack)->op[0] == '(')
			ft_lstadd_back(stack,ft_lstnew(ft_substr(line, ints->len, yes), prio));
		else if(ft_lstlast(*stack)->prio < prio)
			ft_lstadd_back(stack,ft_lstnew(ft_substr(line, ints->len, yes), prio));
		else
		{
			str = ft_strjoin(str, ft_lstlast(*stack)->op);
			ft_lstdellast(stack);
			ft_lstadd_back(stack,ft_lstnew(ft_substr(line, ints->len, yes), prio));
		}
	}
	ints->tmp = ints->len + yes;
	ints->len += yes;
	return (str);
}

char *postfix_expression(char *line)
{
	t_int	ints;
	t_stack *stack;
	char	*poxfix;

	poxfix = NULL;
	stack = NULL;
	ints.len = 0;
	ints.tmp = 0;
	while(line[ints.len])
	{
		if(line[ints.len] == '|' && line[ints.len + 1] == '|')
			poxfix = ft_strjoin(poxfix, get_op_nd_cmd(line, &stack, &ints, 2));
		else if (line[ints.len] == '&' && line[ints.len + 1]== '&')
			poxfix = ft_strjoin(poxfix, get_op_nd_cmd(line, &stack, &ints, 2));
		else if(line[ints.len] == '|' && line[ints.len + 1] != '|')
			poxfix = ft_strjoin(poxfix, get_op_nd_cmd(line, &stack, &ints, 1));
		else if(line[ints.len] == '>' && line[ints.len + 1] == '>')
			poxfix = ft_strjoin(poxfix, get_op_nd_cmd(line, &stack, &ints, 2));
		else if(line[ints.len] == '<' && line[ints.len + 1] == '<')
			poxfix = ft_strjoin(poxfix, get_op_nd_cmd(line, &stack, &ints, 2));
		else if(line[ints.len] == '<' && line[ints.len + 1] != '<')
			poxfix = ft_strjoin(poxfix, get_op_nd_cmd(line, &stack, &ints, 1));
		else if(line[ints.len] == '>' && line[ints.len + 1] != '>')
			poxfix = ft_strjoin(poxfix, get_op_nd_cmd(line, &stack, &ints, 1));
		else if(line[ints.len] == '(')
			poxfix = ft_strjoin(poxfix, get_op_nd_cmd(line, &stack, &ints, 1));
		else if(line[ints.len] == ')')
			poxfix = ft_strjoin(poxfix, get_op_nd_cmd(line, &stack, &ints, 1));
		else
			ints.len++;
	}
	poxfix = ft_strjoin(poxfix, get_op_nd_cmd(line, &stack, &ints, 666));
	return (poxfix);
}

