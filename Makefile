CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lmlx -framework OpenGL -framework AppKit -L./libft -lft
SRC = so_long.c utils/get_next_line.c utils/get_next_line_utils.c utils/movement.c utils/load_images.c utils/map_parser.c utils/map_parser_utils.c utils/map_path_check.c 
OBJ = $(SRC:.c=.o)
TARGET = so_long
LIBFT = libft/libft.a

all: $(LIBFT) $(TARGET)

$(LIBFT):
	@make -C libft

$(TARGET): $(OBJ)
	@$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(TARGET)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re