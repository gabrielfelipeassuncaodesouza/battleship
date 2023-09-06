PROJ_NAME=battleship
OBJS=main.o board.o render.o shoot.o human.o

CC=gcc
CCFLAGS=-Wall -pedantic -std=c99 -g

$(PROJ_NAME): $(OBJS)
	$(CC) -o $(PROJ_NAME) $(OBJS) $(CCFLAGS)

clear:
	@ rm -rf battleship *.o
run:
	@ ./battleship
