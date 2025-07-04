NAME    = philo

CC      = cc
CFLAGS  = -Wall -Werror -Wextra -pthread -g3 -fsanitize=address
INCLUDE = -Iinclude/

OBJ_DIR     = obj
HEADER      = include/philo.h

SRC_FILES   = 	\
				$(addprefix free/,\
					free_dinner.c\
				)\
				$(addprefix output/,\
					print_action.c\
				)\
				$(addprefix parse/,\
					init_dinner.c\
					parse_utils.c\
				)\
				$(addprefix routine/,\
					routine.c\
				)\
				philo.c\

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