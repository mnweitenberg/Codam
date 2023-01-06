# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweitenb <mweitenb@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/23 18:09:27 by mweitenb      #+#    #+#                  #
#    Updated: 2022/12/06 12:01:27 by mweitenb      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# VARIABLES
NAME			:=	interface_and_recap
CFLAGS			:=	-Wall -Wextra -Werror -std=c++98
SANIT			:=	#-fsanitize=address -g
CC				:=	@c++

# STATIC
RM				:=	@rm
MKDIR_P			:=	@mkdir -p
INC_DIR			:=	./inc
SRC_DIR			:=	./src
OBJ_DIR			:=	./obj
SRC				:=	main \
					AMateria \
					Character \
					Cure \
					Ice \
					MateriaSource
INTERFACE		:=	./inc/ICharacter.hpp \
					./inc/IMateriaSource.hpp
OBJ				:=	$(SRC:%=$(OBJ_DIR)/%.o)
$(NAME)			: 	$(OBJ)
					$(CC) $(OBJ) -o $@ $(SANIT)
$(OBJ_DIR)/%.o	:	$(SRC_DIR)/%.cpp $(INC_DIR)/%.hpp $(INTERFACE)
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
