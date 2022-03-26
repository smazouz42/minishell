/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdellast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 4DeR <4DeR@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:34:46 by smazouz           #+#    #+#             */
/*   Updated: 2022/03/26 12:31:21 by 4DeR             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_lstdellast(t_stack *stack)
{
    t_stack   *tmp;

    tmp = stack->prev;
    tmp->next = NULL;
    // free(stack->op);
    // free(stack);
}