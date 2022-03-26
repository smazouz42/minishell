/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdellast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:34:46 by smazouz           #+#    #+#             */
/*   Updated: 2022/03/26 11:40:22 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_lstdellast(t_stack *stack)
{
    t_stack   *tmp;

    tmp = stack->prev;
    tmp->next = NULL;
    free(stack->op);
    free(stack);
}