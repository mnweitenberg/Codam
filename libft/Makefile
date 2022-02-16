NAME		:= 	libft.a
CC			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror
HEADERFILES := 	libft.h
AR			= 	ar rcs
RM			= 	rm -f
FILES		= 	ft_isalpha		\
				ft_isdigit		\
				ft_isalnum		\
				ft_isascii		\
				ft_isprint		\
				ft_strlen		\
				ft_memset		\
				ft_bzero		\
				ft_memcpy		\
				ft_memmove		\
				ft_strlcpy		\
				ft_strlcat		\
				ft_toupper		\
				ft_tolower		\
				ft_strchr		\
				ft_strrchr		\
				ft_strncmp		\
				ft_memchr		\
				ft_memcmp		\
				ft_strnstr		\
				ft_atoi			\
				ft_calloc		\
				ft_strdup		\
				ft_substr		\
				ft_strjoin		\
				ft_strtrim		\
				ft_split		\
				ft_itoa			\
				ft_strmapi		\
				ft_striteri 	\
				ft_putchar_fd	\
				ft_putstr_fd	\
				ft_putendl_fd	\
				ft_putnbr_fd

FILES_B		= 	ft_lstnew_bonus 		\
				ft_lstadd_front_bonus	\
				ft_lstsize_bonus		\
				ft_lstlast_bonus		\
				ft_lstadd_back_bonus	\
				ft_lstdelone_bonus		\
				ft_lstclear_bonus		\
				ft_lstiter_bonus		\
				ft_lstmap_bonus

SRCS_DIR	= 	./
SRCS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_B)))
OBJS_DIR	= 	./
OBJS		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))

ifdef WITH_BONUS
OBJ_FILES 	= $(OBJS) $(OBJS_B)
else
OBJ_FILES 	= $(OBJS)
endif

all			: $(NAME)
$(NAME)		: $(OBJ_FILES)
			$(AR) $@ $^
.c.o		: $(SRCS)
			$(CC) $(CFLAGS) -c -o $@ $<
bonus		:
			$(MAKE) WITH_BONUS=1 all
clean		:
			$(RM) $(OBJS) $(OBJS_B)
fclean		: clean
			$(RM) $(NAME)
re			: clean all
.PHONY		: all bonus clean fclean re
