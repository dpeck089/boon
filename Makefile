Make: src/*
	gcc -I/usr/local/Cellar/sdl2/2.0.5/include/SDL2 -L/usr/local/lib -lSDL2 -o dist/main src/main.c
