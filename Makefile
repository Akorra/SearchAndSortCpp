CC = g++
CFLAGS = -wall -g

main: main.o 
    $(CC) $(CFLAGS) -o main main.o 

main.o: main.cpp Search.h
    $(CC) $(CFLAGS) -c main.cpp