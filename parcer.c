/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:49:39 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/24 14:53:29 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	parcer(char *input)
{
	if(check_errors(input) == 1)
		return ;
	// input = add_parentheses(input);
	// printf("%s\n", input);
}