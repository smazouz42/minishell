/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:34:15 by smazouz           #+#    #+#             */
/*   Updated: 2022/03/30 15:49:43 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

static char	**free_tab(char	**tab)
{
	int	x;

	x = 0;
	while (tab[x])
	{
		free(tab[x]);
		x++;
	}
	free(tab[x]);
	return (NULL);
}

char	*get_next_word(char *s, char c, int *len)
{
	int				x;
	unsigned int	y;
	unsigned int	start;

	x = 0;
	y = 0;
	start = *len;
	while (s[start] == c)
		start++;
	while (s[x + start] != '\0' && s[x + start] != c)
		x++;
	*len = x;
	return (s + start);
}

int	ft_word_count(const char *str, char c)
{
	size_t	x;
	size_t	y;

	y = 0;
	x = 0;
	if (str[x] == c && c != '\0')
		x++;
	while (str[x])
	{
		if (str[x] == c)
		{
			if (str[x - 1] != c)
				y++;
		}
		x++;
	}
	if (str[x - 1] != c && str[x - 1] != '\0')
		y++;
	return (y);
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	char			*temp;
	int				*len2;
	int				k;
	int				i;

	if (!s)
		return (NULL);
	i = -1;
	k = 0;
	temp = (char *)s;
	str = (char **)malloc((ft_word_count(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	len2 = &k;
	while (ft_word_count(s, c) > ++i)
	{
		temp = get_next_word(temp, c, len2);
		str[i] = (char *)malloc((*len2 + 1) * sizeof(char));
		if (!str[i])
			return (free_tab(str));
		ft_strlcpy(str[i], temp, (*(len2) + 1));
	}
	str[i] = NULL;
	return (str);
}
/*
int    main(void)
{
  char **p;
	int i;
	char s[]="";
	p = ft_split("", ' ');
	i = 0;
	  printf("%s\n",p[0]);
	  return(0);
}
*/
