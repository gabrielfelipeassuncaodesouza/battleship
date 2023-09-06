PROJ_NAME=battleship

SRC_DIR=./src
C_SRC=$(wildcard $(SRC_DIR)/*.c)

OBJS=$(C_SRC:.c=.o)
OBJS_TEST=$(subst ./src/main.o, ./tests/test.o, $(OBJS))

CC=gcc
CCFLAGS=-I$(SRC_DIR) -Wall -pedantic -std=c99 -g

all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJS)
	$(CC) -o $(PROJ_NAME) $(OBJS) $(CCFLAGS)

test: $(OBJS_TEST)
	$(CC) -o test $(OBJS_TEST) $(CCFLAGS)
	@ ./test

clear:
	@ rm -rf *.o $(PROJ_NAME) .*.o ./tests/*.o ./tests/.*.o ./src/*.o ./src/.*.o *~
run:
	@ ./battleship
