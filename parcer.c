/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:49:39 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/30 17:29:52 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	 ft_get_item_prio(char *item)
{
	int index;

	index = 0;
	while(item[index])
	{
		if(item[index] != ' ')
			{
				if(item[index] == '|' && item[index + 1] == '|')
					return(1);
				else if (item[index] == '&' && item[index + 1] == '&')
					return(1);
				else if (item[index] == '|' && item[index + 1] != '|')
					return(3);
				else if (item[index] == '<' || item[index + 1] ==  '>')
					return(4);
				else if(item[index] == '(' || item[index + 1] == ')')
					return(5);
				else
					return(6);
			}
		item++;
	}
	return(0);
}
void ft_make_cmd_ap_list(t_stack **items_lst, char **items)
{
	int node_n;
	int prio;

	node_n = 0;
	while(*items)
	{
		prio = ft_get_item_prio(*items);
		if(node_n == 0)
		{
			*items_lst = ft_lstnew(*items, prio);
			node_n++;
		}
		else
			ft_lstadd_back(items_lst,ft_lstnew(*items, prio));
		items++;
	}
}
void	parser(char *input)
{
	// if(check_errors(input) == 1)
	// 	return ;
	t_stack *items_lst;

	items_lst = NULL;
	input = postfix_expression(input);
	ft_make_cmd_ap_list(&items_lst, ft_split(input,','));
}