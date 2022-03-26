/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:19:57 by smazouz           #+#    #+#             */
/*   Updated: 2022/03/25 10:09:24 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	ft_lstdelone(t_stack *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->op);
	free(lst);
}
