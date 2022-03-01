# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweitenb <mweitenb@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/17 16:51:06 by mweitenb      #+#    #+#                  #
#    Updated: 2022/02/17 16:51:06 by mweitenb      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	fractol
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
LINKS			=	-I/usr/include -Imlx_linux -O3
FILES			= 	main		\
					color		\
					fractol		\
					utils		\
					interaction
SRC_DIR			=	./src/
INC_DIR			=	./inc/
SRC				= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
INC				= 	$(addprefix $(INC_DIR), $(addsuffix .h, $(FILES)))
OBJ				=	$(SRC:.c=.o)

%.o				:	%.c $(INC)
					$(CC) $(CFLAGS) -Imlx -c -o $@ $<
all				:	$(NAME)
$(NAME)			:	$(OBJ)
					$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean			:
					rm -f $(OBJ)
fclean			:	clean
					rm -f all
re				: 	fclean all
.PHONY			:	all clean fclean re
norm			:
					norminette $(SRC) $(INC)
