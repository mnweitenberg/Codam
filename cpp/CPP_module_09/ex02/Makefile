# VARIABLES
NAME			:=	PmergeMe
CFLAGS			:=	-Wall -Wextra -Werror -std=c++98 -pedantic -I inc
CC				:=	@c++

# STATIC
RM				:=	@rm
SRC				:=	src/main.cpp \
					src/PmergeMe.cpp
$(NAME)			:	$(SRC) 
					$(CC) $(CFLAGS) $(SRC) -o $(NAME)

.PHONY			:	all clean fclean re
all				:	$(NAME)
clean			:
					rm -rf $(NAME)
fclean			:	clean
re				:	fclean all

