/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:01:36 by smazouz           #+#    #+#             */
/*   Updated: 2022/03/25 10:26:19 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			x;
	size_t			len2;

	x = 0;
	if (!s)
		return (NULL);
	len2 = ft_strlen(s);
	if (len > len2)
		len = len2;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (start <= len2)
	{
		while (s[x] && len > x)
		{
			str[x] = s[start];
			x++;
			start++;
		}
	}
	str[x] = '\0';
	return (str);
}