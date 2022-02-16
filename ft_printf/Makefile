NAME 		:= 	libftprintf.a
CC			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror #-fsanitize=address
AR			= 	ar rcs
RM			= 	rm -f
SRC			=	ft_printf.c 	\
				capture.c 		\
				print_string.c 	\
				print_integer.c \
				utils.c
INCLUDE		=	ft_printf.h

OBJ			=	$(SRC:.c=.o)

$(NAME)		: 	$(INCLUDE) $(OBJ) $(NAME)($(OBJ))
%.o			: 	%.c $(INCLUDE)
				$(CC) -c $(CFLAGS) -o $@ $<
$(NAME)(%.o):	%.o
				ar rcs $(NAME) $<
all			: 	$(NAME)
bonus		: 	$(NAME)
clean		:
				rm -f $(OBJ)
fclean		:	clean
				rm -f $(NAME)
re			: 	fclean all
norm		:
				norminette $(SRC) $(INCLUDE)