#Constants
CC=gcc
O=bin
S=src
FLAGS=-w -Werror -Wall -g
SDL_CFLAGS=`sdl2-config --cflags --libs`


#Compilation
run: $(O)/main.o
	$(CC) -o run $^ $(SDL_CFLAGS) $(FLAGS) 
$(O)/main.o:
	$(CC) -o $(O)/main.o -c $(S)/main.c $(SDL_CFLAGS) $(FLAGS)
clean:
	rm -rf bin/*.o

cleanrun: clean
	make run
