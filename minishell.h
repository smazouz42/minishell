/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:58:57 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/17 16:41:12 by moulmado         ###   ########.fr       */
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
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>

# define PROMPT "\033[0;32m➜  \033[1;36mminishell \033[0;33m✗ \033[0;0m"

//utils
char	*ft_strjoin(char *s0, char *s1);
int		slen(char *c);
int		ft_strchr(char *str, int c);
char	*ft_strdup(char *s);
void	error_msg(char *error);
void	color(int c_nb);

//4 parce
void	parcer(char *input);
int		check_errors(char *input);
char	*add_parentheses(char *input);


#endif