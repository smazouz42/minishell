NAME = minishell
INC = minishell.h
SRC = utils.c parcer.c check_errors.c postfix_expression.c ft_lstadd_back.c ft_lstclear.c ft_lstdellast.c ft_lstdelone.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_substr.c ft_split.c \
		ft_strlcpy.c utils0.c tree_of_life.c execution.c cmd_path.c ft_strlen.c ft_path_split.c ft_strcmp.c here_doc_utils.c here_doc_utils_1.c ft_putstr_fd.c ft_alpha_numeric.c
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
	$(CC) $(CFLAGS) $(MAIN) $(OBJ) -L $(shell brew --prefix readline)/lib -I $(shell brew --prefix readline)/include -lreadline -o $(NAME)
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
# utils.c parcer.c check_errors.c add_parentheses.c