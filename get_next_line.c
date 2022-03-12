/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:17:44 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/12 15:20:49 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*second_part(char *keep)
{
	char	*new_keep;
	int		i;
	int		j;

	i = 0;
	while (keep[i] && keep[i] != '\n')
		i++;
	if (!keep[i])
		return (free(keep), NULL);
	new_keep = (char *)malloc(ft_strlen(keep) - i);
	if (!new_keep)
		return (NULL);
	i++;
	j = 0;
	while (keep[i])
		new_keep[j++] = keep[i++];
	new_keep[j] = '\0';
	return (free(keep), new_keep);
}

static char	*firs_part(char *keep)
{
	char	*next_line;
	int		i;

	i = 0;
	if (!*keep)
		return (NULL);
	while (keep[i] && keep[i] != '\n')
		i++;
	next_line = (char *)malloc(i + 2);
	if (!next_line)
		return (NULL);
	i = 0;
	while (keep[i] && keep[i] != '\n')
	{
		next_line[i] = keep[i];
		i++;
	}
	if (keep[i] == '\n')
		next_line[i++] = '\n';
	next_line[i] = '\0';
	return (next_line);
}

static char	*add_buffer(int fd, char *keep)
{
	char	*tmp;
	int		c;

	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	c = 1;
	while (ft_strchr(keep, '\n') && c)
	{
		c = read(fd, tmp, BUFFER_SIZE);
		if (c == -1)
			return (free(tmp), NULL);
		tmp[c] = '\0';
		keep = ft_strjoin(keep, tmp);
	}
	return (free(tmp), keep);
}

char	*get_next_line(int fd)
{
	static char	*keep;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strchr(keep, '\n'))
		keep = add_buffer(fd, keep);
	if (!keep)
		return (NULL);
	next_line = firs_part(keep);
	keep = second_part(keep);
	return (next_line);
}