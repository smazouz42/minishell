/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:58:57 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/13 11:44:05 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUFFER_SIZE 1
# define red 0
# define blue 1
# define cyan 2
# define yellow 3
# define white 4
# define green 5
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>

char	*get_next_line(int fd);

//for get_next_line
char	*ft_strjoin(char *s0, char *s1);
int		ft_strlen(char *c);
int		ft_strchr(char *str, int c);
char	*ft_strdup(char *s);

#endif