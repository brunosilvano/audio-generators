CC=gcc
CXX=clang++

FLAGS=-Wall -std=c11
CXXFLAGS=-Wall -std=c++17

# Set Libs and Include paths according to OS
LIBS=-lsndfile
INCLUDE=-I/usr/local/include/
LIBS+=-L/usr/local/lib/

BUID_PATH=build
C_PATH=src/C
CXX_PATH=src

all: build_dir sine square table

sine:
	$(CC) -o $(BUID_PATH)/sinegen $(C_PATH)/sinegen.c $(FLAGS) $(INCLUDE) $(LIBS)

square:
	$(CXX) -o $(BUID_PATH)/sqrgen $(CXX_PATH)/sqrgen.cpp $(CXXFLAGS) $(INCLUDE) $(LIBS)

table:
	$(CC) -o $(BUID_PATH)/tablegen $(C_PATH)/tablegen.c $(FLAGS) $(INCLUDE) $(LIBS)

build_dir:
	mkdir -p $(BUID_PATH)
