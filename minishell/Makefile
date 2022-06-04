# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: marvin <marvin@student.42.fr>                +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/23 18:09:27 by mweitenb      #+#    #+#                  #
#    Updated: 2022/05/16 22:31:51 by mweitenb      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# VARIABLES
NAME			:=	minishell
CFLAGS			:=	-Wall -Wextra -Werror
SANIT			:=	-fsanitize=address
CC				:=	@gcc -I /Users/$(USER)/.brew/opt/readline/include
READLINE		:=	-lncurses -lreadline -L /Users/$(USER)/.brew/opt/readline/lib

# STATIC
RM				:=	@rm
MKDIR_P			:=	@mkdir -p
INC_DIR			:=	./inc
SRC_DIR			:=	./src
OBJ_DIR			:=	./obj
SRC				:=	minishell.c \
					env/env.c \
					env/env_utils.c \
					env/sort_alphabetically.c \
					lexer/lexer.c \
					lexer/lexer_utils.c \
					lexer/count.c \
					lexer/split.c \
					lexer/split_utils.c \
					lexer/parameters.c \
					lexer/quotes.c \
					lexer/unexpected_input.c \
					lexer/wildcards.c \
					lexer/wildcards_2.c \
					parameter_expansion/parameter_expansion.c \
					parameter_expansion/parameter_expansion_2.c \
					parameter_expansion/parameter_expansion_3.c \
					parser/parser.c \
					parser/parser_utils.c \
					parser/parse_commands.c \
					parser/path.c \
					executor/here_doc.c \
					executor/executor.c \
					executor/executor_utils.c \
					executor/builtins.c \
					executor/builtins_cd.c \
					executor/export_unset_exit/exit.c \
					executor/export_unset_exit/export_unset_exit.c \
					executor/export_unset_exit/export.c \
					executor/export_unset_exit/unset.c \
					executor/export_unset_exit/unset_export_utils.c \
					utils/ft_split.c \
					utils/allocation.c \
					utils/free.c \
					utils/str_compare.c \
					utils/utils.c
OBJ				:=	$(SRC:%.c=$(OBJ_DIR)/%.o)

all				:	$(NAME)

$(NAME)			: 	$(OBJ)
					$(CC) $(OBJ) -o $@ $(READLINE) $(SANIT)

$(OBJ_DIR)/%.o	:	$(SRC_DIR)/%.c $(INC_DIR)/%.h
					$(MKDIR_P) $(dir $@)
					$(CC) $(CFLAGS) $(SANIT) -c $< -o $@

bonus			:	$(NAME)

clean			:
					$(RM) -rf $(OBJ_DIR)

fclean			:	clean
					$(RM) -f $(NAME)

re				: 	fclean all

norm			:
					@norminette $(SRC_DIR) $(INC_DIR)

.PHONY			:	all bonus clean fclean re norm
