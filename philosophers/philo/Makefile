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
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror #-fsanitize=address -g
LDFLAGS			=	-pthread
RM				=	rm -rf
FILES			=	main	\
					threads	\
					utils
INC_DIR			=	./inc/
SRC_DIR			=	./src/
OBJ_DIR			=	./obj/
INC				= 	$(addprefix $(INC_DIR), $(addsuffix .h, $(FILES)))
SRC				= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ				=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all				:	$(NAME)
$(NAME)			:	$(OBJ_DIR) $(OBJ) $(INC)
					$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)
$(OBJ_DIR)		:
					mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c $(INC)
					$(CC) $(CFLAGS) -c $< -o $@
clean			:
					$(RM) $(OBJ_DIR)
fclean			:	clean
					$(RM) $(NAME)
re				:	fclean all
norm			:
					norminette $(SRC) $(INC)
.PHONY			:	all clean fclean re norm