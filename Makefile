CC=gcc

FLAGS=-Wall -std=c11
INCLUDE=-I/usr/local/include/
LIBS=-L/usr/local/lib/ -lsndfile

all:
	$(CC) -o sqrgen sqrgen.c $(FLAGS) $(INCLUDE) $(LIBS)
