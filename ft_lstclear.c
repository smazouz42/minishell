/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:16:05 by smazouz           #+#    #+#             */
/*   Updated: 2022/03/25 10:08:57 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	ft_lstclear(t_stack **lst, void (*del)(void*))
{
	t_stack	*nod;
	t_stack	*temp;

	temp = (*lst);
	while (temp != NULL)
	{
		nod = temp->next;
		ft_lstdelone(temp, del);
		temp = nod;
	}
	*lst = NULL;
}
