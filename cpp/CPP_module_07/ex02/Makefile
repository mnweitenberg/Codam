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

# VARIABLES
NAME			:=	array
CFLAGS			:=	-Wall -Wextra -Werror -std=c++98
SANIT			:=	-fsanitize=address
CC				:=	@c++

# STATIC
RM				:=	@rm
SRC				:=	src/main.cpp
INC				:=	inc/array.hpp
$(NAME)			:	$(SRC) $(INC)
					$(CC) $(CFLAGS) $(SRC) -o $(NAME)

.PHONY			:	all clean fclean re
all				:	$(NAME)
clean			:
					rm -rf $(NAME)
fclean			:	clean
re				:	fclean all

