/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:27:42 by moulmado          #+#    #+#             */
/*   Updated: 2022/04/14 16:23:09 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	cnt;

	cnt = 0;
	while (n)
	{
		if (!s1[cnt] || !s2[cnt] || s1[cnt] != s2[cnt])
			return ((unsigned char)s1[cnt] - (unsigned char)s2[cnt]);
		cnt++;
		n--;
	}
	return (0);
}

int	lst_size(char **lst)
{
	int	size;

	size =0;
	while (lst[size])
		size++;
	return (size);
}

void	color(int c_nb)
{
	if (c_nb == RED)
		write(1, "\033[0;31m", slen("\033[0;31m"));
	if (c_nb == BLUE)
		write(1, "\033[0;34m", slen("\033[0;34m"));
	if (c_nb == CYAN)
		write(1, "\033[1;36m", slen("\033[0;36m"));
	if (c_nb == YELLOW)
		write(1, "\033[0;33m", slen("\033[0;33m"));
	if (c_nb == WHITE)
		write(1, "\033[0;37m", slen("\033[0;37m"));
	if (c_nb == GREEN)
		write(1, "\033[0;32m", slen("\033[0;32m"));
}