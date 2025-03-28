NAME = philo
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I include/

OBJ_DIR = obj

HEADER := include/philo.h

SRC_FILES = \
			main.c\

SRC_FILES := $(addprefix src/, $(SRC_FILES))

OBJ_FILES = $(SRC_FILES:src/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_FILES) $(HEADER)
	ar -rcs $(NAME) $(OBJ_FILES)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)  # Crear el subdirectorio si no existe
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
