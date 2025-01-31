NAME = so_long

SRC = src/main.c src/parsing.c src/gameplay.c src/init.c src/utils.c

OBJS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -g

LIBFT = libft/libft.a

LIBS = -L minilibx-linux -lmlx -lXext -lX11 -lm

CC = gcc

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz  $(LIBFT) -o $(NAME)


$(LIBFT):
	make all -C libft

all: $(NAME)

bonus: all

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@


clean:
	rm -rf $(OBJS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all bonus clean fclean re