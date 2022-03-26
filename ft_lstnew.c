/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:25:02 by smazouz           #+#    #+#             */
/*   Updated: 2022/03/25 12:30:04 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

t_stack	*ft_lstnew(char *op, int prio)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->prio = prio;
	stack->op = op;
	stack->prev = NULL;
	stack->next = NULL;
	return (stack);
}
/*
int main(void)
{
	char a[20]= "lol";
	t_stack *lst;

	lst = ft_lstnew(a);
	printf("%s",lst->content);
}
*/
