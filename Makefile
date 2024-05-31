# -*- Makefile -*-

SRCS = hooks.c julia.c mandel.c main.c utils.c tricorn.c

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : %.c fractol.h
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CC_FLAGS) -c $< -o $@

NAME = fractol

all: $(NAME)

$(NAME): $(OBJECTS_PREFIXED) libft/libft.a
	$(CC) $(OBJECTS_PREFIXED) -lmlx -framework OpenGL -framework AppKit libft/libft.a -o $(NAME)

bonus: all

libft/libft.a:
	make --directory=libft

clean:
	rm -rf $(OBJS_DIR)
	make --directory=libft fclean

fclean: clean
	rm -rf $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re bonus