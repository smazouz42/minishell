/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_here_doc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 04:01:21 by moulmado          #+#    #+#             */
/*   Updated: 2022/04/24 03:26:40 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	replace_del(t_tree *tree, char **env)
{
	int	p[2];

	pipe(p);
	read_from_here_doc(p[1], tree->cmd->name, env);
	tree->cmd = NULL;
	tree->fd = p[0];
	close(p[1]);
}

void	here_doc_execute(t_tree *tree, char **env)
{
	t_tree	*tree_tmp;

	tree_tmp = tree;
	while (tree->branch1)
		tree = tree->branch1;
	while (tree)
	{
		if (ft_strcmp(tree->op, "<<") == 0 && tree->op != NULL)
		{
			replace_del(tree->branch2, env);
		}
		else if (tree->branch2!= NULL)
		{
			if (tree->branch2->op != NULL)
				here_doc_execute(tree->branch2, env);
		}
		if (tree == tree_tmp)
			break;
		tree = tree->previous;
	}
}
