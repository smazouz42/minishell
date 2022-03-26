/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:58:57 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/26 11:46:36 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUFFER_SIZE 1
# define RED 0
# define BLUE 1
# define CYAN 2
# define YELLOW 3
# define WHITE 4
# define GREEN 5
// # define OP 100
// # define CMD 101
# define AND 1
# define OR 1
# define RE 2
# define PIPE 2
# define L_PARENT 998
# define R_PARENT 999
// # define FILE 110
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>

# define PROMPT "\033[0;32m➜  \033[1;36mminishell \033[0;33m✗ \033[0;0m"

typedef struct s_stack
{
    int prio;
    char *op;
    struct t_stack *prev;
    struct t_stack *next;
}           t_stack;
typedef struct s_cmd
{
    int     valid;
    char    *name;
    char    **l;
    char    *path;
} t_cmd;


typedef struct s_op
{
    int     prio;
} t_op;

typedef struct s_file
{
    char    *name;
    char    *mod;
    int     fd;
    t_cmd   *cmd;
} t_file;

// typedef struct s_list
// {
//     int     type;
//     t_file *file;
//     t_cmd   *cmd;
//     t_op    *op;
//     struct s_list *next;
//     struct s_list *prev;
// }   t_stack;

//tree
typedef struct s_tree
{
    struct s_tree  *previous;
    struct s_tree  *branch1;
    struct s_tree  *branch2;
    t_cmd           *cmd;
    t_op            *op;
    t_file          *file;
}               t_tree;
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

//fix_post
char	*ft_substr(char const *s, unsigned int start, size_t len);

//listlinked
int	ft_lstsize(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
void    ft_lstdellast(t_stack *stack);
#endif