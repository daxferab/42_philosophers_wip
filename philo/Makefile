NAME    = philo

CC      = cc
CFLAGS  = -Wall -Werror -Wextra -pthread -g3 #-fsanitize=thread
INCLUDE = -Iinclude/

OBJ_DIR     = obj
HEADER      = include/philo.h

SRC_FILES   = 	\
				$(addprefix dinner/,\
					init_params.c\
					join_philos.c\
					start_dinner.c\
				)\
				$(addprefix routines/,\
					death_routine.c\
					philo_routine.c\
					routine_eat.c\
					routine_sleep.c\
					routine_think.c\
				)\
				$(addprefix utils/,\
					check_simulation.c\
					free_dinner.c\
					get_time.c\
					libft.c\
					print_action.c\
					safe_functions.c\
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