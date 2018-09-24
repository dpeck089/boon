UNAME := $(shell uname -s)
ifeq ($(UNAME), Darwin)
	INCLUDE_PATH = -I/usr/local/Cellar/sdl2/2.0.5/include/SDL2
	LIB_PATH = -L/usr/local/lib
endif
ifeq ($(UNAME), Linux)
	INCLUDE_PATH = -I/usr/include/SDL2
	LIB_PATH = ""
endif

Make: src/*
	gcc $(INCLUDE_PATH) $(LIB_PATH) -lSDL2 -o dist/main src/main.c
