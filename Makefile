NAME=philo

OS_NAME := $(shell uname -s)

$(HOME) := $(shell echo $HOME)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -O2

OBJ_DIR_NAME = obj

SRCS_NAME = main.c philo_init.c philo_error.c philo_exit.c philo_main_loop.c\
			philo_error.c philo_init_pos.c philo_display_philosophers.c\
			philo_display_baguettes.c philo_philosophers.c\
			philo_routine_philosophers.c

SRCS_PATH = ./srcs/

INCLUDES = ./includes

INCLUDES_LIBFT = ./libft/includes

BREW_INCLUDES  = $(HOME)/.brew/include

LIBS = -lft -lSDL2

LIBFT_PATH = ./libft

LIB_BREW_PATH = $(HOME)/.brew/lib/

OBJ_SRCS = $(SRCS_NAME:%.c=$(OBJ_DIR_NAME)/%.o)

all: $(NAME)

libft:
	make -C $(LIBFT_PATH)

$(NAME):$(OBJ_SRCS)
	make -C $(LIBFT_PATH)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) -L$(LIBFT_PATH) -L$(LIB_BREW_PATH)

$(OBJ_DIR_NAME)/%.o : $(SRCS_PATH)/%.c
	mkdir -p $(OBJ_DIR_NAME)
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDES) -I$(INCLUDES_LIBFT) -I$(BREW_INCLUDES)

sdl:
ifeq ($(OS_NAME),Darwin)
	brew install -y SDL2
endif
ifeq ($(OS_NAME),Linux)
	sudo apt-get install -y SDL2
endif

norminette:
	@echo norme libft
	norminette libft/**/*.[ch]
	@echo norme includes
	norminette ./includes/

clean :
	rm -rf $(OBJ_DIR_NAME)
	make -C $(LIBFT_PATH) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re : fclean all

.PHONY : all clean fclean re libft norminette sdl
