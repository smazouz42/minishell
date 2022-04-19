/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_of_life.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:13:08 by moulmado          #+#    #+#             */
/*   Updated: 2022/04/19 02:52:37 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**lstlcpy(char **lst, int start, int end)
{
	char	**re;
	int		index;

	index = 0;
	re = (char **)malloc(sizeof(char *) * (end - start + 2));
	while (start <= end)
		re[index++] = lst[start++];
	re[index] = NULL;
	return (re);
}

static char	**split_cmd_lst(char **lst, int size, int reset)
{
	static int	start;
	int			end;

	if (reset)
		start = 0;
	end = size - 2;
	if (start)
		return (lstlcpy(lst, 0, start - 1));
	if (lst[size - 2][0] == ' ')
		start = size - 2;
	else
	{
		size -= 2;
		while (size > 0)
		{
			if (lst[size][0] != ' ' && lst[size - 1][0] == ' ' && lst[size - 2][0] == ' ')
			{
				start = size - 2;
				break;
			}
			size--;
		}
	}
	return (lstlcpy(lst, start, end));
}

static void	growing_branches(t_tree *tree, char **lst, int size, char **env)
{
	t_tree	*branch1;
	t_tree	*branch2;

	branch1 = malloc(sizeof(t_tree));
	branch2 = malloc(sizeof(t_tree));
	tree->branch1 = branch1;
	tree->branch2 = branch2;
	branch1->previous = tree;
	branch2->previous = tree;
	tree_expansion(branch2, split_cmd_lst(lst, size, 1), env);
	tree_expansion(branch1, split_cmd_lst(lst, size, 0), env);
}

void	tree_expansion(t_tree *tree, char **lst, char **env)
{
	int		i;
	int		size;

	size = lst_size(lst);
	i = 0;
	if (lst[size - 1][0] != ' ')
	{
		tree->cmd = NULL;
		tree->op = lst[size - 1] + 1;
		growing_branches(tree, lst, size, env);
	}
	else
	{
		tree->branch1 = NULL;
		tree->branch2 = NULL;
		tree->op = NULL;
		tree->cmd = malloc(sizeof(t_cmd));
		tree->cmd->name = lst[0];
		tree->cmd->path = cmd_path(env,lst[0]);
	}
}

t_tree	*tree_of_life(char **lst, char **env)
{
	t_tree	*tree;

	tree = malloc(sizeof(t_tree));
	tree->previous = NULL;
	tree_expansion(tree, lst, env);
	return (tree);
}