NAME = minishell
INC = minishell.h
SRC = minishell.c utils.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	@$(CC) $(CFLAGS) $(OBJ) -L /goinfre/moulmado/.brew/opt/readline -lreadline -o $(NAME)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclear all