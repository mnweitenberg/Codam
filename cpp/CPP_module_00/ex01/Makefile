NAME			=	phonebook
CC				=	@c++
FLAGS			=	-Wall -Wextra -Werror -std=c++98 -fsanitize=address
FILES			=	main		\
					Contact		\
					PhoneBook
SRC				= 	$(addsuffix .cpp, $(FILES))
INC				= 	$(addsuffix .hpp, $(FILES))
OBJ				=	$(SRC:.cpp=.o)

all				:	$(NAME)
$(NAME)			:	$(OBJ)
					$(CC) $(FLAGS) -o $@ $^
%.o				: 	%.cpp $(INC)
					$(CC) $(FLAGS) -o $@ $< -c
clean			:
					@rm -f $(OBJ)
fclean			:	clean
					@rm -f $(NAME)
re				: 	fclean all
.PHONY			:	all clean fclean re
