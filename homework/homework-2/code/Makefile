# This is a basic makefile to compile a program.

CC=g++
CFLAGS=-Wall -Wfatal-errors

SRC=*.cpp

PROGRAM=main

.PHONY: all
all: ${PROGRAM}

${PROGRAM}: ${SRC}
	${CC} ${CFLAGS} -o ${PROGRAM}  ${SRC}

.PHONY: clean
clean:
	rm -rf *.o ${PROGRAM} 
