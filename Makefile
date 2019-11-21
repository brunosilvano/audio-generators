CC=gcc

FLAGS=-Wall -std=c11

# Get OS name
UNAME:=$(shell uname)

# Set Libs and Include paths according to OS
LIBS=-lsndfile
ifeq ($(UNAME), Linux)
INCLUDE=-I/usr/local/include/
LIBS+=-L/usr/local/lib/
endif
ifeq ($(UNAME), Darwin)
INCLUDE=-I/usr/local/Cellar/libsndfile/1.0.28/include
LIBS+=-L/usr/local/Cellar/libsndfile/1.0.28/lib
endif

all:
	$(CC) -o sqrgen sqrgen.c $(FLAGS) $(INCLUDE) $(LIBS)
