# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweitenb <mweitenb@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/23 18:09:27 by mweitenb      #+#    #+#                  #
#    Updated: 2022/12/12 13:31:14 by mweitenb      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# VARIABLES
NAME			:=	mutated_abomination
CFLAGS			:=	-Wall -Wextra -Werror -std=c++98
CC				:=	@c++

# STATIC
RM				:=	@rm
SRC				:=	src/main.cpp
INC				:=	inc/MutantStack.hpp
$(NAME)			:	$(SRC) $(INC)
					$(CC) $(CFLAGS) $(SRC) -o $(NAME)

.PHONY			:	all clean fclean re
all				:	$(NAME)
clean			:
					rm -rf $(NAME)
fclean			:	clean
re				:	fclean all

