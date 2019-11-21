CC=gcc

FLAGS=-Wall -std=c11

# Get OS name
UNAME:=$(shell uname)

# Set Libs and Include paths according to OS
ifeq ($(UNAME), Linux)
INCLUDE=-I/usr/local/include/
LIBS=-L/usr/local/lib/ -lsndfile
endif
# TODO: add paths for MacOS system

all:
	$(CC) -o sqrgen sqrgen.c $(FLAGS) $(INCLUDE) $(LIBS)
