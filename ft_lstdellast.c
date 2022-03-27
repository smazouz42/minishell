/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdellast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:34:46 by smazouz           #+#    #+#             */
/*   Updated: 2022/03/27 15:13:24 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_lstdellast(t_stack **stack)
{
    t_stack   *tmp;

	if (!ft_lstlast(*stack)->prev)
	{
		free((*stack)->op);
		free(*stack);
		*stack = NULL;
		return ;
	}
    tmp = ft_lstlast(*stack)->prev;
    free(ft_lstlast(*stack)->op);
    free(ft_lstlast(*stack));
    tmp->next = NULL;
}