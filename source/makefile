.DEFAULT_GOAL := run

###   CHANGE   ###
LIBS :=
NAME := exe
CC  := gcc
CFLAGS := -g -W
### END CHANGE ###

SRC = main.c
DEPS := main.h ops.h
OBJECTS :=$(patsubst %.c,%.o, $(SRC))

%.o: SRC $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) -L./ -l gbsdl -lSDL2 $(sdl2-config --cflags) -Wl,-rpath=./

clean:
	@echo $(shell rm $(NAME) $(OBJECTS) libgbsdl.so)
	@echo $(shell rm -r -f )

run:
	@echo $(shell make compile)
	./$(NAME)

v:
	@echo $(shell make $(NAME))
	@echo $(shell valgrind ./$(NAME))

compile:
	@echo $(shell make display)
	@echo $(shell make $(NAME))

display:
	clang++ -shared -fPIC -o libgbsdl.so display.cpp exception.cpp