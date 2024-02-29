# This is a basic makefile to compile a program.

CC=g++
CFLAGS=-Wall -Wfatal-errors -lm

SRC=main.cpp
PROGRAM=main

.PHONY: all
all: ${PROGRAM}

program: ${SRC}
	${CC} ${CFLAGS} -o ${PROGRAM}  ${SRC}

.PHONY: clean
clean:
	rm -rf *.o ${PROGRAM} 
