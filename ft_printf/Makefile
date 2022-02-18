# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 19:41:19 by mweitenb          #+#    #+#              #
#    Updated: 2022/02/18 13:50:03 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= 	libftprintf.a
CC			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror
AR			= 	ar rcs
RM			= 	rm -f
SRC			=	src/ft_printf.c 	\
				src/capture.c 		\
				src/print_string.c 	\
				src/print_integer.c \
				src/utils.c
INCLUDE		=	inc/ft_printf.h

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