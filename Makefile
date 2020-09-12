CC=gcc
CXX=clang++

FLAGS=-Wall -std=c11
CXXFLAGS=-Wall -std=c++17

# Get OS name
UNAME:=$(shell uname)

# Set Libs and Include paths according to OS
LIBS=-lsndfile
INCLUDE=-I/usr/local/include/
LIBS+=-L/usr/local/lib/

all: sine square

sine:
	$(CC) -o sinegen sinegen.c $(FLAGS) $(INCLUDE) $(LIBS)

square:
	$(CXX) -o sqrgen sqrgen.cpp $(CXXFLAGS) $(INCLUDE) $(LIBS)

table:
	$(CC) -o tablegen tablegen.c $(FLAGS) $(INCLUDE) $(LIBS)
