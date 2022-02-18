NAME			=	pipex
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror #-fsanitize=address
SRC				=	src/main.c 		\
					src/path.c		\
					src/split.c 	\
					src/error.c 	\
					src/here_doc.c	\
					src/utils.c
INC				=	inc/pipex.h

OBJ				=	$(SRC:.c=.o)

all				:	$(NAME)
bonus			:	$(NAME)
$(NAME)			:	$(OBJ)
					$(CC) $(CFLAGS) -o $@ $^
%.o				: 	%.c $(INC)
					$(CC) $(CFLAGS) -o $@ $< -c
clean			:
					rm -f $(OBJ)
fclean			:	clean
					rm -f all
re				: 	fclean all
.PHONY			:	all clean fclean re
norm			:
					norminette $(SRC) $(INC)