NAME = so_long

SRC = src/main.c src/parsing.c src/gameplay.c src/init.c src/free.c src/animation.c src/map.c\
		src/utils.c src/flood_fill.c

OBJS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -g

LIBFT = libft/libft.a

LIBS = -lmlx -lXext -lX11 -lm

CC = gcc

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS)  $(LIBS) $(LIBFT) -o $(NAME)


$(LIBFT):
	make all -C libft

all: $(NAME)

%.o: %.c
	$(CC) -I/usr/include $(FLAGS) -c $< -o $@


clean:
	rm -rf $(OBJS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all bonus clean fclean re