NAME = minishell
INC = minishell.h
SRC = utils.c parser.c check_errors.c postfix_expression.c stacklst/ft_stackadd_back.c \
		stacklst/ft_stackclear.c stacklst/ft_stackdellast.c stacklst/ft_stackdelone.c \
		stacklst/ft_stacklast.c stacklst/ft_stacknew.c stacklst/ft_stacksize.c ft_substr.c \
		ft_split.c ft_strlcpy.c utils0.c tree_of_life.c execution.c execute_here_doc.c \
		cmd_path.c ft_strlen.c ft_path_split.c ft_strcmp.c here_doc_utils.c \
		here_doc_utils_1.c ft_putstr_fd.c ft_alpha_numeric.c execution_utils.c rm_rf_spaces.c \
		envlst/envadd_back.c envlst/envlast.c envlst/envnew.c envlst/envsize.c \
		builtins/pwd.c builtins/env.c builtins/cd.c 
# SRC = $(shell ls *.c)
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MAIN = minishell.c

RED = \033[0;36m

RESET = \033[0m

all : $(NAME)
	@echo "$(RED) \
		███╗   ███╗██╗███╗  ██╗██╗ ██████╗██╗  ██╗███████╗██╗     ██╗    \n\
		████╗ ████║██║████╗ ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     \n\
		██╔████╔██║██║██╔██╗██║██║╚█████╗ ███████║█████╗  ██║     ██║     \n\
		██║╚██╔╝██║██║██║╚████║██║ ╚═══██╗██╔══██║██╔══╝  ██║     ██║     \n\
		██║ ╚═╝ ██║██║██║ ╚███║██║██████╔╝██║  ██║███████╗███████╗███████╗\n\
		╚═╝     ╚═╝╚═╝╚═╝  ╚══╝╚═╝╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝ \n $(RESET)"

$(NAME) : $(OBJ) $(INC) $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) $(OBJ) -L $(shell brew --prefix readline)/lib -I \
	$(shell brew --prefix readline)/include -lreadline -o $(NAME)
.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@
clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
# utils.c parcer.c check_errors.c add_parentheses.c