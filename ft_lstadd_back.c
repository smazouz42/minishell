/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:12:11 by smazouz           #+#    #+#             */
/*   Updated: 2022/03/25 12:29:14 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*node;

	if (*lst == NULL)
		*lst = new;
	else
	{
		node = ft_lstlast(*lst);
		node->next = new;
		new->prev = node;
	}
}
