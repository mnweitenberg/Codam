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
NAME			:=	conversion_of_scalar_types
CFLAGS			:=	-Wall -Wextra -Werror -std=c++98
SANIT			:=	-fsanitize=address
CC				:=	@c++

# STATIC
RM				:=	@rm
MKDIR_P			:=	@mkdir -p
INC_DIR			:=	./inc
SRC_DIR			:=	./src
OBJ_DIR			:=	./obj
SRC				:=	main \
					identify \
					Convert
OBJ				:=	$(SRC:%=$(OBJ_DIR)/%.o)
$(NAME)			: 	$(OBJ)
					$(CC) $(OBJ) -o $@ $(SANIT)
$(OBJ_DIR)/%.o	:	$(SRC_DIR)/%.cpp $(INC_DIR)/%.hpp
					$(MKDIR_P) $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@

.PHONY			:	all bonus clean fclean re
all				:	$(NAME)
bonus			:	$(NAME)
clean			:
					$(RM) -rf $(OBJ_DIR)
fclean			:	clean
					$(RM) -f $(NAME)
re				: 	fclean all
