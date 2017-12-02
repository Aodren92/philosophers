NAME=philo

OS_NAME := $(shell uname -s)

all:$(NAME)

sdl:
ifeq ($(OS_NAME),Darwin)
	brew install -y SDL2
endif
ifeq ($(OS_NAME),Linux)
	sudo apt-get install -y SDL2
endif

