CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror #-fsanitize=address
SRC				=	common/main.c 				\
					common/actions.c 			\
					common/utils.c 				\
					common/list_utils.c
SRC_SORT		=	sort/push_swap.c 			\
					sort/sort_small_stacks.c 	\
					sort/move_a_to_b.c 			\
					sort/move_b_to_a.c 			\
					sort/execute_rotations.c
SRC_CHECK		=	check/checker.c
INC				=	includes/push_swap.h

OBJ				=	$(SRC:.c=.o)
OBJ_SORT		=	$(SRC_SORT:.c=.o)
OBJ_CHECK		=	$(SRC_CHECK:.c=.o)

%.o				: 	%.c $(INC)
					$(CC) $(CFLAGS) -o $@ $< -c
push_swap		:	$(OBJ) $(OBJ_SORT)
					$(CC) $(CFLAGS) -o $@ $^
checker			:	$(OBJ) $(OBJ_CHECK)
					$(CC) $(CFLAGS) -o $@ $^
all				: 	push_swap checker
clean			:
					rm -f $(OBJ) $(OBJ_SORT) $(OBJ_CHECK)
fclean			:	clean
					rm -f push_swap checker
re				: 	fclean all
norm			:
					norminette $(SRC) $(SRC_SORT) $(SRC_CHECK) $(INCLUDE)