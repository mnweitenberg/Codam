# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweitenb <mweitenb@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/23 18:09:27 by mweitenb      #+#    #+#                  #
#    Updated: 2022/02/23 18:09:27 by mweitenb      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	philo
CC				=	gcc -pthread
CFLAGS			=	-Wall -Wextra -Werror #-fsanitize=address
FILES			=	main	\
					threads	\
					utils
SRC_DIR			=	./src/
INC_DIR			=	./inc/
SRC				= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
INC				= 	$(addprefix $(INC_DIR), $(addsuffix .h, $(FILES)))
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
