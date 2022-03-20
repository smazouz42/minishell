/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:49:39 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/20 13:22:19 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	parcer(char *input)
{
	check_errors(input);
	input = add_parentheses(input);
}