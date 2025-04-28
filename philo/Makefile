NAME    = philo

CC      = cc
CFLAGS  = -Wall -Werror -Wextra
INCLUDE = -Iinclude/

OBJ_DIR     = obj
HEADER      = include/philo.h

SRC_FILES   = 	philo.c\
				$(addprefix output/,\
					print_action.c\
					print_error.c\
				)\
				$(addprefix parse/,\
					init_args.c\
				)\

SRC_FILES   := $(addprefix src/, $(SRC_FILES))
OBJ_FILES   = $(SRC_FILES:src/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_FILES) $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ_FILES) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c $(HEADER) | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re