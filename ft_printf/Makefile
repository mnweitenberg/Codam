# VARIABLES
NAME 			:= 	libftprintf.a
CFLAGS			:=	-Wall -Wextra -Werror
SANIT			:=	#-fsanitize=address -g
CC				:= 	gcc

# STATIC
AR				= 	ar
RM				=	rm -rf
MKDIR_P			:=	mkdir -p
FILES			:=	ft_printf	 	\
					capture 		\
					print_string 	\
					print_integer	\
					utils
INC_DIR			=	./inc/
SRC_DIR			=	./src/
OBJ_DIR			=	./obj/
INC				= 	$(addprefix $(INC_DIR), $(addsuffix .h, $(FILES)))
SRC				= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ				=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

$(NAME)			:	$(OBJ_DIR) $(OBJ) $(INC) $(NAME)($(OBJ))
$(OBJ_DIR)		:
					$(MKDIR_P) $(OBJ_DIR)
$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c $(INC)
					$(CC) -c $(CFLAGS) -o $@ $<
$(NAME)(%.o)	:	$(OBJ_DIR)%.o
					$(AR) $(NAME) $< 

all				:	$(NAME)
bonus			:	$(NAME)
clean			:
					$(RM) $(OBJ_DIR)
fclean			:	clean
					$(RM) $(NAME)
re				: 	fclean all
.PHONY			:	all bonus clean fclean re norm
norm			:
					@norminette $(SRC_DIR) $(INC_DIR)
