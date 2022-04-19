/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:49:39 by moulmado          #+#    #+#             */
/*   Updated: 2022/04/19 19:43:51 by smazouz          ###   ########.fr       */
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
static void	cleanse(char *s)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == ',' && s[index + 1] == ' ')
			s[index + 1] = ',';
		index++;
	}
}
t_tree	*parser(char *input, char **env)
{
	if(check_errors(input) == 1)
		return(NULL);
	input = postfix_expression(input);
	cleanse(input);
	return (tree_of_life(ft_split(input,','),env));
}