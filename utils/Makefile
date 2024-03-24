# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Linker flags
LDFLAGS = -lmlx -framework OpenGL -framework AppKit

# Source file
SRC = so_long.c

# Object file
OBJ = $(SRC:.c=.o)

# Executable
TARGET = so_long

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
