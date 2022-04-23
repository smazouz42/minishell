/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:58:57 by moulmado          #+#    #+#             */
/*   Updated: 2022/04/23 06:20:31 by moulmado         ###   ########.fr       */
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
# define OP 100
# define CMD_LINE 101
# define AND 1
# define OR 1
# define RE 2
# define PIPE 2
# define L_PARENT 998
# define R_PARENT 999
# define EXODIA 666
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
#include <fcntl.h>

# define PROMPT "➜  mminishell ✗ "

typedef struct s_stack
{
    int				prio;
    char			*op;
    struct s_stack	*prev;
    struct s_stack	*next;
}				t_stack;
typedef struct s_int
{
    int	len;
    int	tmp;
}				t_int;
typedef struct s_cmd
{
    // int		valid;
    char	*name;
    // char	**l;
    char	*path;
    // char    *new
}				t_cmd;

typedef struct s_file
{
    char	*name;
    char	*mod;
    int		fd;
    t_cmd	*cmd;
}				t_file;

//tree
typedef struct s_tree
{
    struct s_tree	*previous;
    struct s_tree	*branch1;
    struct s_tree	*branch2;
    t_cmd			*cmd;
    char			*op;
    int             fd;
	int				branch_type;
}				t_tree;
//utils
char	*ft_strjoin(char *s0, char *s1);
int		slen(char *c);
int		ft_strchr(char *str, int c);
char	*ft_strdup(char *s);
void	error_msg(char *error);
void	color(int c_nb);
int		ft_strncmp(char *s1, char *s2, int n);
int		lst_size(char **lst);
size_t ft_strlen(const char *str);
char	**ft_path_split(char const *s, char c);
int     ft_strcmp(char *s1, char *s2);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int	is_alpha_n(char c);

//4 parce
t_tree	*parser(char *input, char **env);
int		check_errors(char *input);
char	*add_parentheses(char *input);
char	*postfix_expression(char *line);
void	tree_expansion(t_tree *tree, char **lst, char **env);
t_tree	*tree_of_life(char **lst, char **env);

//fix_post
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t destsize, int start);

//listlinked
int		ft_lstsize(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstdellast(t_stack **stack);
t_stack	*ft_lstnew(char *op, int prio);
void	ft_lstdelone(t_stack *lst, void (*del)(void *));

//execution
void	here_doc_execute(t_tree *tree, char **env);
int    ft_execution(t_tree *tree, char **env, int ou, int in);
char    *cmd_path(char **env , char *cmd);
char	*ft_find_path(char **env, const char *path);

//here_doc_functions
int		read_from_here_doc(int fd_in, char *limiter, char **env);
int     check_for_dollar(char *line);
char	*up_line(char *line, char **env);
char	*ft_make_new_line(char *line, char *var, int size, int dollar_number);
char	*rest_of_line(char *line);
char	*ft_read(void);
char	*var_name(char *line);
int     ft_get_line(char *line);

#endif