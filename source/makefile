.DEFAULT_GOAL := run

###   CHANGE   ###
LIBS :=
NAME := exe
DIR := # build/
CC  := gcc
CFLAGS := -g -W
### END CHANGE ###

SRC = main.c
DEPS := main.h ops.h
OBJECTS :=$(patsubst %.c,$(DIR)%.o, $(SRC))

dir_exists: | $(DIR)
	@echo 

$(DIR)%.o: SRC $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJECTS)
	$(CC) -o $(DIR)$@ $^ $(CFLAGS)

clean: 
	@echo $(shell pushd $(DIR))
	@echo $(shell rm $(NAME) $(OBJECTS) viewer)
	@echo $(shell popd)
	@echo $(shell rm -r -f $(DIR))

run:
	$(shell make dir_exists)
	@echo $(shell make $(NAME))
	./$(DIR)$(NAME)

v:
	@echo $(shell make $(NAME))
	@echo $(shell valgrind ./$(DIR)$(NAME))

compile:
	@echo $(shell make $(NAME))

$(DIR):
	mkdir -p $@

sdl_install:
	sudo apt-get update
	sudo apt-get install libsdl2-dev -y
	sudo apt-get install clang -y
	sudo apt-get install clang++ -y
	clang++ -shared -fPIC -o libgbsdl.so display.cpp exception.cpp

viewer:
	clang -o viewer viewer.c -L./ -l gbsdl -lSDL2 $(sdl2-config --cflags)
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./
	./viewer
